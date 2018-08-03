import com.es.trade.*;

import java.util.concurrent.atomic.AtomicInteger;

public class TradeWrap extends IEsunnyTradeSpi
{
    private IEsunnyTradeApi _api;
    private String _certKey;
    private String _logFilePath;
    private String _appId;
    private String _ip;
    private int _port;
    private String _clientId;
    private String _password;



    private AtomicInteger _reqId;

    public TradeWrap(){

    }

    private int GetReqId(){
       return  _reqId.getAndIncrement();
    }

    public void Start(){
        SWIGTYPE_p_int result = es_trade.new_intp();


        _api =  es_trade.CreateEsunnyForeignTradeApi(_certKey,result,_logFilePath,_appId);
        System.out.println("CreateEsunnyForeignTradeApi:" + es_trade.intp_value(result));

        _api.SetSpi(this);
        es_trade.delete_intp(result);

        TEsAddressField addressField = new TEsAddressField();

        addressField.setIp(_ip);
        addressField.setPort(_port);

        boolean openResult = _api.Open(addressField);
        System.out.println("Open:" + openResult);

    }

    @Override
    public void OnOpen() {
        System.out.println("OnOpen");


        TEsLoginReqField loginReqField = new TEsLoginReqField();
        loginReqField.setIsCaLogin('N');
        loginReqField.setIdentity('c');
        loginReqField.setIsForcePwd('N');
        loginReqField.setClientNo(_clientId);
        loginReqField.setLoginPwd(_password);

        SWIGTYPE_p_int reqId = es_trade.new_intp();
        es_trade.intp_assign(reqId,GetReqId());
        int loginResult = _api.Login(loginReqField,reqId);
        es_trade.delete_intp(reqId);

        System.out.println("Login:" + loginResult);

    }

    @Override
    public void OnClose() {
        System.out.println("OnClose");
    }

    @Override
    public void OnLogin(TEsLoginRspField rsp, int errCode, int iReqID) {
        System.out.println("OnLogin:" + errCode);


    }

    @Override
    public void OnRtnContact(SWIGTYPE_p_a_201__char rsp, boolean islast, int errCode) {
        System.out.println("OnRtnContact");
    }

    @Override
    public void OnRspRequestVertificateCode(TEsRequestVertificateCodeRsp rsp, int errCode, int iReqID) {

    }

    @Override
    public void OnInitFinished(int errCode) {
        System.out.println("OnInitFinished:" + errCode);
        SWIGTYPE_p_int reqId = es_trade.new_intp();
        es_trade.intp_assign(reqId,GetReqId());

        TEsMoneyQryReqField reqField = new TEsMoneyQryReqField();
        reqField.setClientNo(_clientId);
        int result = _api.QryMoney(reqField,reqId);

        System.out.println("QryMoney:" + result);
        es_trade.delete_intp(reqId);
    }

    @Override
    public void OnLogOut(int errCode, int iReqID) {

    }

    @Override
    public void OnRspSetPassword(TEsClientPasswordModifyRspField rsp, int errCode, int iReqID) {

    }

    @Override
    public void OnRspSetOperPassword(TEsOperatorPasswordModifyRspField rsp, int errCode, int iReqID) {

    }

    @Override
    public void OnQryMoney(TEsMoneyQryRspField rsp, boolean islast, int errCode, int iReqID) {
    if(rsp != null)
        System.out.println("ClientNo:" + rsp.getClientNo()
                + " CurrencyNo:" + rsp.getCurrencyNo()
                + " TBalacce:" + rsp.getTBalance()
                + " TCanCashOut:" + rsp.getTBalance()
                + " AccountMarketValue:" + rsp.getAccountMarketValue());
    else
        System.out.println("TEsMoneyQryRspField is null!");
    }

    @Override
    public void OnRtnMoney(TEsMoneyChgNoticeField rsp) {

    }

    @Override
    public void OnRspCashOperQry(TEsCashOperQryRspField rsp, boolean islast, int errCode, int iReqID) {

    }

    @Override
    public void OnRspCashOper(TEsCashOperRspField rsp, int errCode, int iReqID) {

    }

    @Override
    public void OnRtnCashOper(TEsCashOperRspField rsp) {

    }

    @Override
    public void OnRspCashCheck(TEsCashOperRspField rsp, int errCode, int iReqID) {

    }

    @Override
    public void OnRtnCashCheck(TEsCashOperRspField rsp) {

    }

    @Override
    public void OnRspCashAdjustQry(TEsAdjustQryRspField rsp, boolean islast, int errCode, int iReqID) {

    }

    @Override
    public void OnRspOrderInsert(TEsOrderInsertRspField rsp, int errCode, int iReqID) {

    }

    @Override
    public void OnRspOrderModify(TEsOrderModifyRspField rsp, int errCode, int iReqID) {

    }

    @Override
    public void OnRspOrderDelete(TEsOrderDeleteRspField rsp, int errCode, int iReqID) {

    }

    @Override
    public void OnRspQryOrder(TEsOrderInfoNoticeField rsp, boolean islast, int errCode, int iReqID) {

    }

    @Override
    public void OnRspHistOrderQry(TEsHisOrderQryRspField rsp, boolean islast, int errCode, int iReqID) {

    }

    @Override
    public void OnRtnOrderState(TEsOrderStateNoticeField rsp) {

    }

    @Override
    public void OnRtnOrderInfo(TEsOrderInfoNoticeField rsp) {

    }

    @Override
    public void OnRspMatchQry(TEsMatchInfoNoticeField rsp, boolean islast, int errCode, int iReqID) {

    }

    @Override
    public void OnRtnMatchState(TEsMatchStateNoticeField rsp) {

    }

    @Override
    public void OnRtnMatchInfo(TEsMatchInfoNoticeField rsp) {

    }

    @Override
    public void OnRspHistMatchQry(TEsHisMatchQryRspField rsp, boolean islast, int errCode, int iReqID) {

    }

    @Override
    public void OnQryHold(TEsHoldQryRspField rsp, boolean islast, int errCode, int iReqID) {

    }

    @Override
    public void OnRtnHold(TEsHoldQryRspField rsp) {

    }

    @Override
    public void OnQryExchangeState(TEsExchangeQryRspField rsp, boolean islast, int errCode, int iReqID) {

    }

    @Override
    public void OnRtnExchangeState(TEsExchangeStateModifyNoticeField rsp) {

    }

    @Override
    public void OnQryCommodity(TEsCommodityQryRspField rsp, boolean islast, int errCode, int iReqID) {

    }

    @Override
    public void OnQryContract(TEsContractQryRspField rsp, boolean islast, int errCode, int iReqID) {

    }

    @Override
    public void OnQryClient(TEsOperatorClientQryRspField rsp, boolean islast, int errCode, int iReqID) {

    }

    @Override
    public void OnRspHistCashOperQry(TEsHisCashOperQryRspField rsp, boolean islast, int errCode, int iReqID) {

    }

    @Override
    public void OnRspHistCashAdjustQry(TEsHisAdjustQryRspField rsp, boolean islast, int errCode, int iReqID) {

    }

    @Override
    public void OnRspAuthClient(TEsClientPasswordAuthRspField rsp, int errCode, int iReqID) {

    }

    @Override
    public void OnRspQryCurrency(TEsCurrencyQryRspField rsp, boolean islast, int errCode, int iReqID) {

    }

    @Override
    public void OnRtnExchangeRateMod(TEsExchangeRateModifyNoticeField rsp) {

    }

    @Override
    public void OnRtnOrderRemove(TEsOrderRemoveNoticeField rsp) {

    }

    @Override
    public void OnRtnMatchRemove(TEsMatchRemoveNoticeField rsp) {

    }

    @Override
    public void OnRtnCommodityState(TEsCommodityStateModNoticeField rsp) {

    }

    @Override
    public void OnRtnContractAdd(TEsContractQryRspField rsp) {

    }

    @Override
    public void OnRspQryMonitorEvent(TEsMonitorEventQryRspField rsp, boolean islast, int errCode, int iReqID) {

    }

    @Override
    public void OnRtnMonitorEvent(TEsMonitorEventQryRspField rsp) {

    }

    @Override
    public void OnRspHKMarketOrder(TEsHKMarketOrderReq rsp, int errCode, int iReqID) {

    }

    @Override
    public void OnRspQryClientCountRent(TClientCountRentQryRsp rsp, boolean islast, int errCode, int iReqID) {

    }

    @Override
    public void OnRspQryLmeContract(TEsQryLmeContractRspField rsp, int errCode, int iReqID) {

    }

    @Override
    public void OnRtnLmeContract(TEsQryLmeContractRspField info) {

    }

    @Override
    public void OnRspQryHisHold(TEsHisHoldQryRspField rsp, boolean islast, int errCode, int iReqID) {

    }

    @Override
    public void OnRspQryHisMoney(TEsHisMoneyQryRspField rsp, boolean islast, int errCode, int iReqID) {

    }


}

