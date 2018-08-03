import com.es.quote.*;

public class QuotationReceiver extends ITapQuoteAPINotify{

    private ITapQuoteAPI api;

    public QuotationReceiver(){

        }

        public int ReqQryCommodity(){

            SWIGTYPE_p_unsigned_int sessionId = es_quote.new_unsignedintp();
            int result = api.QryCommodity(sessionId);
            es_quote.delete_unsignedintp(sessionId);
            return result;
        }

        public int ReqQryContract(String commodityNo,String exchangeNo,char commodityType)
        {
            TapAPICommodity com = new TapAPICommodity();
            com.setCommodityNo(commodityNo);
            com.setExchangeNo(exchangeNo);
            com.setCommodityType(commodityType);

            SWIGTYPE_p_unsigned_int sessionId = es_quote.new_unsignedintp();

            int result = api.QryContract(sessionId,com);
            es_quote.delete_unsignedintp(sessionId);
            return result;
        }

        public int SubscribeQuote(String exchangeNo,char commodityType,String commodityNo,String contractNo1)
        {
            TapAPIContract contract = new TapAPIContract();

            contract.getCommodity().setExchangeNo(exchangeNo);
            contract.getCommodity().setCommodityType(commodityType);
            contract.getCommodity().setCommodityNo(commodityNo);
            contract.setContractNo1(contractNo1);
            contract.setCallOrPutFlag1('N');
            contract.setCallOrPutFlag2('N');

            SWIGTYPE_p_unsigned_int sessionId = es_quote.new_unsignedintp();
            int result = api.SubscribeQuote(sessionId,contract);
            es_quote.delete_unsignedintp(sessionId);
            return  result;
        }

        public int UnSubscribeQuote(String exchangeNo,char commodityType,String commodityNo,String contractNo1)
        {
            TapAPIContract contract = new TapAPIContract();

            contract.getCommodity().setExchangeNo(exchangeNo);
            contract.getCommodity().setCommodityType(commodityType);
            contract.getCommodity().setCommodityNo(commodityNo);
            contract.setContractNo1(contractNo1);
            contract.setCallOrPutFlag1('N');
            contract.setCallOrPutFlag2('N');

            SWIGTYPE_p_unsigned_int sessionId = es_quote.new_unsignedintp();
            int result = api.UnSubscribeQuote(sessionId,contract);
            es_quote.delete_unsignedintp(sessionId);
            return  result;
        }

        public void Start(){

        }

        @Override
        public void OnRspLogin(int errorCode, TapAPIQuotLoginRspInfo info) {
            //super.OnRspLogin(errorCode, info);
            System.out.println("OnRspLogin errorCode:" + errorCode);

            //ReqQryCommodity();
        }

        @Override
        public void OnAPIReady() {
            //super.OnAPIReady();
            System.out.println("OnAPIReady");
        }

        @Override
        public void OnDisconnect(int reasonCode) {
            System.out.println("OnDisconnect:" + reasonCode);
            //super.OnDisconnect(reasonCode);
        }

        @Override
        public void OnRspQryCommodity(long sessionID, int errorCode, char isLast, TapAPIQuoteCommodityInfo info) {
            //super.OnRspQryCommodity(sessionID, errorCode, isLast, info);

            System.out.println(info.getCommodity().getCommodityNo());
        }

        @Override
        public void OnRspQryContract(long sessionID, int errorCode, char isLast, TapAPIQuoteContractInfo info) {
            //super.OnRspQryContract(sessionID, errorCode, isLast, info);
        }

        @Override
        public void OnRspSubscribeQuote(long sessionID, int errorCode, char isLast, TapAPIQuoteWhole info) {
            //super.OnRspSubscribeQuote(sessionID, errorCode, isLast, info);
        }

        @Override
        public void OnRspUnSubscribeQuote(long sessionID, int errorCode, char isLast, TapAPIContract info) {
            //super.OnRspUnSubscribeQuote(sessionID, errorCode, isLast, info);
        }

        @Override
        public void OnRtnQuote(TapAPIQuoteWhole info) {
            //super.OnRtnQuote(info);
        }
}
