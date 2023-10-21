import java.util.LinkedList;
import java.util.Queue;

//<T> means generic Type

public class BlockQueue<T> {
    private Queue<T> queue = new LinkedList<>();
    private int maxSize;

    public BlockQueue(int maxSize) {
        this.maxSize = maxSize;
    }

    public synchronized void push(T value) {
        while (queue.size() == maxSize) {
            try {
                // Wait for the queue to have space
                wait();
            } catch (InterruptedException e) {
                // If interrupted, print an error message and immediately exit the push.
                System.err.println("Interrupted during wait: " + e.getMessage());
                Thread.currentThread().interrupt();
                return;
            }
        }
        queue.add(value);
        System.out.println("Produced -> " + value);
        // Notify all waiting threads that the queue state has changed
        notifyAll();
    }

    public synchronized void pop() {
        while (queue.isEmpty()) {
            try {
                // Wait for the queue to have elements
                wait();
            } catch (InterruptedException e) {
                // If interrupted, print an error message and immediately exit the pop.
                System.err.println("Interrupted during wait: " + e.getMessage());
                Thread.currentThread().interrupt();
                return;
            }
        }
        T value = queue.remove();
        System.out.println("Consumed -> " + value);
        // Notify all waiting threads that the queue state has changed
        notifyAll();
    }

    public static void main(String[] args) {
        BlockQueue<Integer> bq = new BlockQueue<>(3);

        Thread producer = new Thread(() -> {
            for (int i = 0; i < 10; i++) {
                bq.push(i);
                try {
                    // Simulate time passing during production
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    // If interrupted during sleep, restore interruption status and exit
                    System.err.println("Producer was interrupted: " + e.getMessage());
                    Thread.currentThread().interrupt();
                    return;
                }
            }
        });

        Thread consumer = new Thread(() -> {
            for (int i = 0; i < 10; i++) {
                bq.pop();
                try {
                    // Simulate time passing during consumption
                    Thread.sleep(500);
                } catch (InterruptedException e) {
                    // If interrupted during sleep, restore interruption status and exit
                    System.err.println("Consumer was interrupted: " + e.getMessage());
                    Thread.currentThread().interrupt();
                    return;
                }
            }
        });

        producer.start();
        consumer.start();

        try {
            producer.join();
            consumer.join();
        } catch (InterruptedException e) {
            // If the current thread was interrupted while waiting for producer and consumer to finish
            System.err.println("Main thread was interrupted while waiting for threads to finish: " + e.getMessage());
            Thread.currentThread().interrupt();
        }
    }
}
