public class Main {
    public static void main (String[] args) {
        UserBucketCreator userbucket = new UserBucketCreator(1);
        for(int i=0; i<12; i++) {
            userbucket.accessApplication(1);
        }
    }
}
