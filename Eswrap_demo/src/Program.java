public class Program{
  static {
    System.loadLibrary("EsTradeWrap");
  }



  public static void main(String args[]) {

    TradeWrap tradeWrap = new TradeWrap();
    tradeWrap.Start();

    while (true){
      try {
        Thread.sleep(1000);
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
    }
  }
}
