public class Event {

   public enum EventState {UP, DOWN};

   protected EventState  value;

   public Event(EventState  initial) {
      value = initial;
   }

   public synchronized void await(EventState state)
      throws InterruptedException {
      while (value != state) wait();
   }

   public synchronized void set() {
      value = EventState.UP;
      notifyAll();
   }

   public synchronized void reset() {
      value = EventState.DOWN;
      notifyAll();
   }

   public synchronized void toggle() {
      value = (value == EventState.DOWN ? EventState.UP : EventState.DOWN);
      notifyAll();
   }
   
   public synchronized EventState state() {
	      return value;
	   }

}
