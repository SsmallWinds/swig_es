#ifndef _ESUNNY_FOREIGN_TRADE_API_
#define _ESUNNY_FOREIGN_TRADE_API_

#include "EsForeignApiStruct.h"
#ifdef linux
#define __cdecl
#endif

namespace ESForeign
{
    //交易数据处理的回调处理类，当有数据到达本地时，API会回调本类中对应的接口
    //回调函数不能有阻塞性操作
    //OnRsp开头的函数为发送请求后对应的应答，OnRtn开头的函数为服务器主动推送数据
    class IEsunnyTradeSpi
    {
    public:
        ////////////////////////////////////////
        /// \fn    ~IEsunnyTradeSpi
        /// \brief 纯虚类，需要派生
        /// \return   
        ////////////////////////////////////////
        virtual ~IEsunnyTradeSpi() {};

        ////////////////////////////////////////
        /// \fn    OnOpen
        /// \brief 与服务器建立连接时调用
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnOpen() = 0;

        ////////////////////////////////////////
        /// \fn    OnClose
        /// \brief 与服务器断开连接时调用
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnClose() = 0;

        ////////////////////////////////////////
        /// \fn    OnLogin
        /// \brief 发送Login登陆成功时收到服务器登陆响应调用
        /// \param const TEsLoginRspField & rsp
        /// \param int iReqID
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnLogin(const TEsLoginRspField* rsp, int errCode, const int iReqID) = 0;



		////////////////////////////////////////
		/// \fn    OnRtnContact
		/// \brief 发送Login登陆后如果需要进行动态认证，则返回需要发送的邮箱或者电话
		/// \param const TContactInfoType & rsp
		/// \param TEsIsLastType islast
		/// \param int errCode
		/// \return   void 
		////////////////////////////////////////
		virtual void  OnRtnContact(const TContactInfoType *rsp, TEsIsLastType islast, int errCode) = 0;


		////////////////////////////////////////
		/// \fn    OnRspRequestVertificateCode
		/// \brief 发送请求认证码之后的应答
		/// \param const TContactInfoType & rsp
		/// \param int errCode
		/// \param int iReqID
		/// \return   void 
		////////////////////////////////////////
		virtual void  OnRspRequestVertificateCode(const TEsRequestVertificateCodeRsp *rsp, int errCode,const int iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    OnInitFinished
        /// \brief 发送Login成功后，收到OnLogin应答成功后收到初始化操作完成
        ///        所有的业务操作需要在本响应errCode为0（成功）后可进行
        /// \param int errCode 错误码，0-成功，其他值-错误的原因代码
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnInitFinished(int errCode) = 0;

        ////////////////////////////////////////
        /// \fn    OnLogOut
        /// \brief 收到登出应答调用
        /// \param int errCode
        /// \param const int iReqID
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnLogOut(int errCode, const int iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    OnRspSetPassword
        /// \brief  修改客户密码时应答，返回信息包括修改密码详细内容
        /// \param const TEsClientPasswordModifyRspField & rsp
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRspSetPassword(const TEsClientPasswordModifyRspField* rsp, int errCode, const int iReqID){};

        ////////////////////////////////////////
        /// \fn    OnRspSetOperPassword
        /// \brief 修改操作员密码时应答，返回信息包括修改密码详细内容
        /// \param const TEsOperatorPasswordModifyRspField & rsp
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRspSetOperPassword(const TEsOperatorPasswordModifyRspField* rsp, int errCode, const int iReqID) {};

        ////////////////////////////////////////
        /// \fn    OnQryMoney
        /// \brief 资金查询应答
        /// \param TEsMoneyQryRspField * rsp 查询完成时，指针为空，未完成时包含查询结果
        /// \param TEsIsLastType islast 指示是否查询完成，完成时rsp指针为空
        /// \param const int iReqID 对应发送请求的ID
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnQryMoney(const TEsMoneyQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};
        
        ////////////////////////////////////////
        /// \fn    OnRtnMoney
        /// \brief 资金变化推送通知
        /// \param TEsMoneyChgNoticeField & rsp 资金变化详细信息
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRtnMoney(const TEsMoneyChgNoticeField& rsp) {};

        ////////////////////////////////////////
        /// \fn    OnRspCashOperQry
        /// \brief 出金入金查询应答
        /// \param TEsCashOperRspField * rsp查询完成时，指针为空，未完成时包含查询结果
        /// \param TEsIsLastType islast 指示是否查询完成，完成时rsp指针为空
        /// \param const int iReqID 对应发送请求的ID
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRspCashOperQry(const TEsCashOperQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};
        
        ////////////////////////////////////////
        /// \fn    OnRspCashOper
        /// \brief 出金入金操作应答
        /// \param TEsCashOperRspField * rsp 出入金操作的详细结果
		/// \param const int iReqID 对应发送请求的ID
		/// \note   不要在此函数中同步执行非强制出金的CashCheck
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRspCashOper(const TEsCashOperRspField* rsp, int errCode, const int iReqID) {};
        
        ////////////////////////////////////////
        /// \fn    OnRtnCashOper
		/// \brief 出金入金操作推送通知
		/// \param TEsCashOperNoticeField & rsp 出入金操作的详细信息
		/// \return   void 
		/// \note   不要在此函数中同步执行非强制出金的CashCheck
        ////////////////////////////////////////
        virtual void  OnRtnCashOper(const TEsCashOperNoticeField& rsp) {};
        
        ////////////////////////////////////////
        /// \fn    OnRspCashCheck
        /// \brief 出金入金审核应答
        /// \param TEsCashCheckRspField * rsp 出入金审核的详细结果
        /// \param const int iReqID 对应发送请求的ID
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRspCashCheck(const TEsCashCheckRspField* rsp, int errCode, const int iReqID) {};
        
        ////////////////////////////////////////
        /// \fn    OnRtnCashCheck
        /// \brief 出金入金审核推送通知
        /// \param TEsCashCheckNoticeField & rsp 出入金审核的详细信息
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRtnCashCheck(const TEsCashCheckNoticeField& rsp) {};

        ////////////////////////////////////////
        /// \fn    OnRspCashAdjustQry
        /// \brief 资金调整查询应答
        /// \param TEsAdjustOperRspField * rsp 查询结果，查询完成时，指针为空
        /// \param TEsIsLastType islast 指示是否查询完成，完成时rsp指针为空
        /// \param const int iReqID 对应发送请求的ID
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRspCashAdjustQry(const TEsAdjustQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};

        ////////////////////////////////////////
        /// \fn    OnRspOrderInsert
        /// \brief 报单请求的应答
        /// \param TEsOrderInsertRspField & rsp 报单请求的详细结果，会返回委托号及本地号
        /// \param const int iReqID 对应发送请求的ID
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRspOrderInsert(const TEsOrderInsertRspField* rsp, int errCode, const int iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    OnRspOrderModify
        /// \brief 改单请求的应答，出错时会收到本应答
        /// \param TEsOrderModifyRspField & rsp
        /// \param const int iReqID 对应发送请求的ID
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRspOrderModify(const TEsOrderModifyRspField* rsp, int errCode, const int iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    OnRspOrderDelete
        /// \brief 撤单请求的应答，出错时会收到本应答
        /// \param TEsOrderDeleteRspField & rsp
        /// \param const int iReqID 对应发送请求的ID
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRspOrderDelete(const TEsOrderDeleteRspField* rsp, int errCode, const int iReqID) = 0;
        
        ////////////////////////////////////////
        /// \fn    OnRspQryOrder
        /// \brief 委托查询应答
        /// \param TEsOrderDataQryRspField * rsp 委托查询结果，查询完成时，指针为空
        /// \param TEsIsLastType islast 指示是否查询完成，完成时rsp指针为空
        /// \param const int iReqID 对应发送请求的ID
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRspQryOrder(const TEsOrderDataQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};
        
        ////////////////////////////////////////
        /// \fn    OnRspHistOrderQry
        /// \brief 历史委托查询应答
        /// \param TEsHisOrderQryRspField * rsp 历史委托查询结果，查询完成时，指针为空
        /// \param TEsIsLastType islast 指示是否查询完成，完成时rsp指针为空
        /// \param const int iReqID 对应发送请求的ID
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRspHistOrderQry(const TEsHisOrderQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};
        
        ////////////////////////////////////////
        /// \fn    OnRtnOrderState
        /// \brief 委托变化通知，委托状态变化时回调
        /// \param TEsOrderStateNoticeField & rsp 委托详细数据
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRtnOrderState(const TEsOrderStateNoticeField& rsp) = 0;
        
        ////////////////////////////////////////
        /// \fn    OnRtnOrderInfo
        /// \brief 委托信息变化通知，委托信息变化时回调
        /// \param TEsOrderInfoNoticeField & rsp 委托信息详细数据
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRtnOrderInfo(const TEsOrderInfoNoticeField& rsp) = 0;

        ////////////////////////////////////////
        /// \fn    OnRspMatchQry
        /// \brief  成交查询应答
        /// \param TEsMatchDataQryRspField * rsp 成交查询结果，查询完成时，指针为空
        /// \param TEsIsLastType islast 指示是否查询完成，完成时rsp指针为空
        /// \param const int iReqID 对应发送请求的ID
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRspMatchQry(const TEsMatchDataQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};

        ////////////////////////////////////////
        /// \fn    OnRtnMatchState
        /// \brief 成交变化推送通知
        /// \param TEsMatchStateNoticeField & rsp 成交详细数据
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRtnMatchState(const TEsMatchStateNoticeField& rsp) = 0;

        ////////////////////////////////////////
        /// \fn    OnRtnMatchInfo
        /// \brief 成交信息变化推送通知
        /// \param TEsMatchInfoNoticeField & rsp 成交信息详细数据
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRtnMatchInfo(const TEsMatchInfoNoticeField& rsp) = 0;

        ////////////////////////////////////////
        /// \fn    OnRspHistMatchQry
        /// \brief 历史成交查询应答
        /// \param TEsHisMatchQryRspField * rsp 历史成交查询结果，查询完成时，指针为空
        /// \param TEsIsLastType islast 指示是否查询完成，完成时rsp指针为空
        /// \param const int iReqID 对应发送请求的ID
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRspHistMatchQry(const TEsHisMatchQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};

        ////////////////////////////////////////
        /// \fn    OnQryHold
        /// \brief 持仓查询应答
        /// \param TEsHoldQryRspField * rsp 持仓查询结果，查询完成时，指针为空
        /// \param TEsIsLastType islast 指示是否查询完成，完成时rsp指针为空
        /// \param const int iReqID 对应发送请求的ID
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnQryHold(const TEsHoldQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};
        
        ////////////////////////////////////////
        /// \fn    OnRtnHold
        /// \brief 持仓变化推送通知，暂时未用
        /// \param TEsHoldQryRspField & rsp 持仓详细信息
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRtnHold(const TEsHoldQryRspField& rsp) {};

        ////////////////////////////////////////
        /// \fn    OnQryExchangeState
        /// \brief 市场状态查询应答
        /// \param TEsExchangeQryRspField * rsp 市场状态详细信息，查询完成时，指针为空
        /// \param TEsIsLastType islast 指示是否查询完成，完成时rsp指针为空
        /// \param const int iReqID 对应发送请求的ID
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnQryExchangeState(const TEsExchangeQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};

        ////////////////////////////////////////
        /// \fn    OnRtnExchangeState
        /// \brief 市场状态变更推送通知
        /// \param TEsExchangeQryRspField & rsp 市场状态详细信息
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRtnExchangeState(const TEsExchangeStateModifyNoticeField& rsp) = 0;

        ////////////////////////////////////////
        /// \fn    OnQryCommodity
        /// \brief 商品查询应答
        /// \param TEsCommodityQryRspField * rsp 商品详细信息，查询完成时，指针为空
        /// \param TEsIsLastType islast 指示是否查询完成，完成时rsp指针为空
        /// \param const int iReqID 对应发送请求的ID
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnQryCommodity(const TEsCommodityQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};

        ////////////////////////////////////////
        /// \fn    OnQryContract
        /// \brief 合约查询应答
        /// \param TEsContractQryRspField * rsp 合约详细信息，查询完成时，指针为空
        /// \param TEsIsLastType islast 指示是否查询完成，完成时rsp指针为空
        /// \param const int iReqID 对应发送请求的ID
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnQryContract(const TEsContractQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};

        ////////////////////////////////////////
        /// \fn    OnQryClient
        /// \brief 交易员下属客户信息查询应答
        /// \param TEsOperatorClientQryRspField * rsp 下属客户详细信息，查询完成时，指针为空
        /// \param TEsIsLastType islast 指示是否查询完成，完成时rsp指针为空
        /// \param const int iReqID 对应发送请求的ID
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnQryClient(const TEsOperatorClientQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};


        ////////////////////////////////////////
        /// \fn    OnRspHistCashOperQry
        /// \brief 历史出金入金查询应答
        /// \param const TEsHisCashQryRspField * rsp
        /// \param TEsIsLastType islast
        /// \param int errCode
        /// \param const int iReqID
        /// \return void 
        ////////////////////////////////////////
        virtual void  OnRspHistCashOperQry(const TEsHisCashOperQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};

        ////////////////////////////////////////
        /// \fn    OnRspCashAdjustQry
        /// \brief 历史资金调整查询应答
        /// \param TEsAdjustOperRspField * rsp 查询结果，查询完成时，指针为空
        /// \param TEsIsLastType islast 指示是否查询完成，完成时rsp指针为空
        /// \param const int iReqID 对应发送请求的ID
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRspHistCashAdjustQry(const TEsHisAdjustQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};

        ////////////////////////////////////////
        /// \fn    OnRspAuthClient
        /// \brief 用户密码验证请求应答
        /// \param const TEsLoginRspField * rsp
        /// \param int errCode
        /// \param const int iReqID
        /// \return void 
        ////////////////////////////////////////
        virtual void  OnRspAuthClient(const TEsClientPasswordAuthRspField* rsp, int errCode, const int iReqID) {};

        ////////////////////////////////////////
        /// \fn    OnRspQryCurrency
        /// \brief 查询货币币种信息应答
        /// \param const TEsCurrencyQryRspField * rsp
        /// \param int errCode
        /// \param const int iReqID
        /// \return void 
        ////////////////////////////////////////
        virtual void  OnRspQryCurrency(const TEsCurrencyQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};

        ////////////////////////////////////////
        /// \fn    OnRtnExchangeRateMod
        /// \brief 币种汇率变化通知
        /// \param const TEsCurrencyQryRspField * rsp
        /// \param TEsIsLastType islast
        /// \param int errCode
        /// \param const int iReqID
        /// \return void 
        ////////////////////////////////////////
        virtual void  OnRtnExchangeRateMod(const TEsExchangeRateModifyNoticeField& rsp) {};

        ////////////////////////////////////////
        /// \fn    OnRtnOrderRemove
        /// \brief 委托删除通知
        /// \param const TEsOrderRemoveNoticeField & rsp
        /// \return void 
        ////////////////////////////////////////
        virtual void  OnRtnOrderRemove(const TEsOrderRemoveNoticeField& rsp) {};

        ////////////////////////////////////////
        /// \fn    OnRtnMatchRemove
        /// \brief 成交删除通知
        /// \param const TEsMatchRemoveNoticeField & rsp
        /// \return void 
        ////////////////////////////////////////
        virtual void  OnRtnMatchRemove(const TEsMatchRemoveNoticeField& rsp) {};

        ////////////////////////////////////////
        /// \fn    OnRtnCommodityState
        /// \brief 商品状态变化通知
        /// \param const TEsCommodityStateModNotice & rsp
        /// \return void 
        ////////////////////////////////////////
        virtual void  OnRtnCommodityState(const TEsCommodityStateModNoticeField& rsp) {};

		////////////////////////////////////////
		/// \fn    OnRtnContractAdd
		/// \brief 合约添加通知
		/// \param const TEsContractAddNoticeField & rsp
		/// \return void 
		////////////////////////////////////////
		virtual void  OnRtnContractAdd(const TEsContractAddNoticeField& rsp) {};
		
		////////////////////////////////////////
		/// \fn    OnRspQryMonitorEvent
		/// \brief 查询监控事件应答
		/// \param const TEsMonitorEventQryRspField * rsp
		/// \param int errCode
		/// \param const int iReqID
		/// \return void 
		////////////////////////////////////////
		virtual void  OnRspQryMonitorEvent(const TEsMonitorEventQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};

		////////////////////////////////////////
		/// \fn    OnRtnMonitorEvent
		/// \brief 监控事件通知
		/// \param const TEsMonitorEventNoticeField & rsp
		/// \return void 
		////////////////////////////////////////
		virtual void  OnRtnMonitorEvent(const TEsMonitorEventNoticeField& rsp) {};

		////////////////////////////////////////
		/// \fn    OnRspMarketOrderInsert
		/// \brief 港交所做市商下单应答
		/// \param const TEsHKMarketOrderRsp * rsp
		/// \param int errCode
		/// \param const int iReqID
		/// \return void 
		////////////////////////////////////////
		virtual void  OnRspHKMarketOrder(const TEsHKMarketOrderRsp* rsp,int errCode,const int iReqID) {};

		////////////////////////////////////////
		/// \fn    OnRspQryClientCountRent
		/// \brief 查询计算参数应答.
		/// \param const TClientCountRentQryRsp * rsp
		/// \param int errCode
		/// \param const int iReqID
		/// \return void 
		////////////////////////////////////////
		virtual void  OnRspQryClientCountRent(const TClientCountRentQryRsp* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};
		////////////////////////////////////////
		/// \fn    OnRspQryLmeContract
		/// \brief 查询LME到期日应答.
		/// \param const TClientCountRentQryRsp * rsp
		/// \param int errCode
		/// \param const int iReqID
		/// \return void 
		////////////////////////////////////////
		virtual void  OnRspQryLmeContract(const TEsQryLmeContractRspField *rsp, int errCode, const int iReqID){};
		////////////////////////////////////////
		/// \fn    OnRtnLmeContract
		/// \brief LME到期日通知.
		/// \param const TLmeContractNotice * rsp
		/// \return void 
		////////////////////////////////////////
		virtual void  OnRtnLmeContract(const TEsLmeContractNotice *info){};
		////////////////////////////////////////
		/// \fn    OnRspQryHisHold
		/// \brief 查询历史持仓应答.
		/// \param const THisHoldQryRsp * rsp
		/// \param int errCode
		/// \param const int iReqID
		/// \return void 
		////////////////////////////////////////
		virtual void  OnRspQryHisHold(const TEsHisHoldQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};
		////////////////////////////////////////
		/// \fn    OnRspQryHisMoney
		/// \brief 查询历史资金应答.
		/// \param const THisHoldQryRsp * rsp
		/// \param int errCode
		/// \param const int iReqID
		/// \return void 
		////////////////////////////////////////
		virtual void  OnRspQryHisMoney(const TEsHisMoneyQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};
    };

    class IEsunnyTradeApi
    {
    public:
        ////////////////////////////////////////
        /// \fn    ~IEsunnyFeTradeApi
        /// \brief 虚析构函数，通过IEsunnyFeTradeApi指针能够删除交易API实例，
        /// 删除交易API实例时，推荐使用Free函数
        /// \return   
        ////////////////////////////////////////
        virtual ~IEsunnyTradeApi(){};

        ////////////////////////////////////////
        /// \fn    SetSpi
        /// \brief 设置回调数据接口，认证API通过后，需要调用本接口设置回调处理类
        /// \param IEsunnyTradeSpi * spi
        /// \return   void 
        ////////////////////////////////////////
        virtual void  SetSpi(IEsunnyTradeSpi* spi) = 0;

        ////////////////////////////////////////
        /// \fn    Free
        /// \brief 释放当前api会话
        /// \return   void 
        ////////////////////////////////////////
        virtual void  Free() = 0;

        ////////////////////////////////////////
        /// \fn    GetErrcodeDesc
        /// \brief 获取错误码的中文描述(多字节编码)
        /// \param int iErrcode
        /// \return   const char* 
        ////////////////////////////////////////
        virtual const char*  GetErrcodeDesc(int iErrcode) = 0;

        ////////////////////////////////////////
        /// \fn    Open
        /// \brief 连接交易服务器，返回成功只表明成功发出连接请求，是否建立连接需要
        /// 调用IsOpen函数
        /// \param TEsAddressField & addr
        /// \return   bool 
        ////////////////////////////////////////
        virtual bool  Open(const TEsAddressField& addr) = 0;

        ////////////////////////////////////////
        /// \fn    Close
        /// \brief 关闭交易服务器连接
        /// \return   void 
        ////////////////////////////////////////
        virtual void  Close() = 0;

        ////////////////////////////////////////
        /// \fn    IsOpen
        /// \brief 获取是否与交易服务器建立连接
        /// \return   bool 
        ////////////////////////////////////////
        virtual bool  IsOpen() = 0;

        ////////////////////////////////////////
        /// \fn    Login
        /// \brief 发送登录请求，暂时支持单客户登陆
        /// \param TEsLoginReq & req
        /// \return   int 
        ////////////////////////////////////////
        virtual int  Login(const TEsLoginReqField& req, int& iReqID) = 0;

		////////////////////////////////////////
		/// \fn    RequestVertificateCode
		/// \brief 发送二次认证授权码
		/// \param TEsLoginReq & req
		/// \return   int 
		////////////////////////////////////////
		virtual int  RequestVertificateCode(const TEsRequestVertificateCodeReq CertificateCode, int& iReqID) = 0;

		////////////////////////////////////////
		/// \fn    SetVertificateCode
		/// \brief 发送二次认证授权码
		/// \param TEsLoginReq & req
		/// \return   int 
		////////////////////////////////////////
		virtual int  SetVertificateCode(const TVertificateCodeType CertificateCode, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    LogOut
        /// \brief 发送退出请求
        /// \return   int 
        ////////////////////////////////////////
        virtual int  LogOut(int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    SetPassword
        /// \brief 修改客户密码
        /// \param TEsSetPassReqField & req
        /// \return   int 
        ////////////////////////////////////////
        virtual int  SetPassword(const TEsClientPasswordModifyReqField& req, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    SetOperPassword
        /// \brief 修改操作员密码，暂时未用
        /// \param const TEsOperatorPasswordModifyReqField & req
        /// \param int & iReqID
        /// \return   int 
        ////////////////////////////////////////
        virtual int  SetOperPassword(const TEsOperatorPasswordModifyReqField& req, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryClients
        /// \brief 查询交易员下属客户，暂时未用
        /// \param const TOperatorClientQryReq & qryClients
        /// \return   int 
        ////////////////////////////////////////
        virtual int  QryClients(const TEsOperatorClientQryReqField& qryClients, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryMoney
        /// \brief 查询客户资金
        /// \param const TMoneyQryReq & qryMoney
        /// \return   int 
        ////////////////////////////////////////
        virtual int  QryMoney(const TEsMoneyQryReqField& qryMoney, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryOrder
        /// \brief 查询客户委托，查询所有数据 流号填0
        /// \param const TOrderQryReq & qryOrder
        /// \return   int 
        ////////////////////////////////////////
        virtual int  QryOrder(const TEsOrderQryReqField& qryOrder, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryMatch
        /// \brief 查询客户成交
        /// \param const TMatchQryReq & qryMatch
        /// \return   int 
        ////////////////////////////////////////
        virtual int  QryMatch(const TMatchQryReqField& qryMatch, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryHold
        /// \brief 查询持仓
        /// \param const THoldQryReq & qryHold
        /// \return   int 
        ////////////////////////////////////////
        virtual int  QryHold(const TEsHoldQryReqField& qryHold, int& iReqID) = 0;


        ////////////////////////////////////////
        /// \fn    QryExchangeState
        /// \brief 查询交易所状态
        /// \param const TExchangeQryReq & qryExg
        /// \return   int 
        ////////////////////////////////////////
        virtual int  QryExchangeState(const TEsExchangeQryReqField& qryExg, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryCommodity
        /// \brief 查询交易商品
        /// \param const TCommodityQryReq & qryCmdy
        /// \return   int 
        ////////////////////////////////////////
        virtual int  QryCommodity(const TEsCommodityQryReqField& qryCmdy, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryContract
        /// \brief 查询合约
        /// \param const TContractQryReq & qryCntr
        /// \return   int 
        ////////////////////////////////////////
        virtual int  QryContract(const TEsContractQryReqField& qryCntr, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    OrderInsert
        /// \brief 报单请求
        /// \param TEsOrderInsertReqField & req
        /// \param int * pReqID
        /// \return   int 
        ////////////////////////////////////////
        virtual int  OrderInsert(const TEsOrderInsertReqField& req, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    OrderModify
        /// \brief 改单请求
        /// \param TEsOrderModifyReqField & req
        /// \return   int 
        ////////////////////////////////////////
        virtual int  OrderModify(const TEsOrderModifyReqField& req, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    OrderDelete
        /// \brief 撤单请求
        /// \param TEsOrderDeleteReqField & req
        /// \return   int 
        ////////////////////////////////////////
        virtual int  OrderDelete(const TEsOrderDeleteReqField& req, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryHistOrder
        /// \brief 历史委托查询
        /// \param TEsHisOrderQryReqField & req
        /// \param int & iReqID
        /// \return   int 
        ////////////////////////////////////////
        virtual int  QryHistOrder(const TEsHisOrderQryReqField& req, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryHistMatch
        /// \brief 历史成交查询
        /// \param TEsHisMatchQryReqField & req
        /// \param int & iReqID
        /// \return   int 
        ////////////////////////////////////////
        virtual int  QryHistMatch(const TEsHisMatchQryReqField& req, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryCashOper
        /// \brief 出金入金查询
        /// \param TEsCashOperQryReqField & req
        /// \param int & iReqID
        /// \return   int 
        ////////////////////////////////////////
        virtual int  QryCashOper(const TEsCashOperQryReqField& req, int& iReqID) = 0;
        
        ////////////////////////////////////////
        /// \fn    CashOper
        /// \brief 出金入金操作请求
        /// \param TEsCashOperReqField & req
        /// \param int & iReqID
        /// \return   int 
        ////////////////////////////////////////
        virtual int  CashOper(const TEsCashOperReqField& req, int& iReqID) = 0;
        
        ////////////////////////////////////////
        /// \fn    CashCheck
        /// \brief 出金入金审核请求
        /// \param TEsCashCheckReqField & req
        /// \param int & iReqID
        /// \return   int 
        ////////////////////////////////////////
        virtual int  CashCheck(const TEsCashCheckReqField& req, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryCachAdjust
        /// \brief 资金调整查询
        /// \param TEsAdjustQryReqField & req
        /// \param int & iReqID
        /// \return   int 
        ////////////////////////////////////////
        virtual int  QryCachAdjust(const TEsAdjustQryReqField& req, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryHistCashOper
        /// \brief 历史出金入金查询
        /// \param const TEsHisCashQryReqField & req
        /// \param int & iReqID
        /// \return int 
        ////////////////////////////////////////
        virtual int  QryHistCashOper(const TEsHisCashOperQryReqField& req, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryHistCachAdjust
        /// \brief 历史资金调整查询
        /// \param const THisAdjustQryReq & req
        /// \param int & iReqID
        /// \return int 
        ////////////////////////////////////////
        virtual int  QryHistCachAdjust(const TEsHisAdjustQryReqField& req, int& iReqID) = 0;     

        ////////////////////////////////////////
        /// \fn    AuthUserPassword
        /// \brief 验证用户名密码
        /// \param const TEsLoginReqField & req
        /// \param int & iReqID
        /// \return int 
        ////////////////////////////////////////
        virtual int  AuthClient(const TEsClientPasswordAuthReqField& req, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryCurrency
        /// \brief 查询货币币种信息
        /// \param const TEsCurrencyQryReqField & req
        /// \param int & iReqID
        /// \return int 
        ////////////////////////////////////////
		virtual int  QryCurrency(const TEsCurrencyQryReqField& req, int& iReqID) = 0;

		////////////////////////////////////////
		/// \fn    GetCertCodeExpireDate
		/// \brief 获取认证码过期日期
		/// \param TDateType & expireDate
		/// \return int 
		////////////////////////////////////////
		virtual int  GetCertCodeExpireDate(TDateType& expireDate) = 0;

		////////////////////////////////////////
		/// \fn    QryMonitorEvent
		/// \brief 查询监控事件
		/// \param const TEsMonitorEventQryReqField & req
		/// \param int & iReqID
		/// \return int 
		////////////////////////////////////////
		virtual int  QryMonitorEvent(const TEsMonitorEventQryReqField& req, int& iReqID) = 0;

		////////////////////////////////////////
		/// \fn    HKMarketOrderInsert
		/// \brief 下港交所做市商报单
		/// \param const THKMarketOrderReq & req
		/// \param int & iReqID
		/// \return int 
		////////////////////////////////////////
		virtual int  HKMarketOrderOperator(const ESForeign::TEsHKMarketOrderReq& req, int& iReqID) = 0;

		////////////////////////////////////////
		/// \fn QryCountRent
		/// \brief 客户计算参数查询
		/// \param const TClientCountRentReq &req
		/// \param int &iReqID
		///\return int 
		///////////////////////////////////////
		virtual int  QryCountRent(const ESForeign::TClientCountRentQryReq &req, int & iReqID) = 0;
		///////////////////////////////////////
		/// \fn QryLmeContract
		/// \brief LME到期日查询
		/// \param int &iReqID
		/// \return int 
		//////////////////////////////////////
		virtual int  QryLmeContract(int &iReqID) = 0;

		//////////////////////////////////////
		/// \fn QryHisHold
		/// \brief 查询历史持仓
		/// \param const THisHoldQryReq &req
		/// \param int &iReqID
		/// \return int 
		/////////////////////////////////////
		virtual int  QryHisHold(const ESForeign::TEsHisHoldQryReqField &req, int &iReqID) = 0;

		//////////////////////////////////////
		/// \fn QryHisHold
		/// \brief 查询历史资金.
		/// \param const THisMoneyQryReq &req
		/// \param int &iReqID
		/// \return int 
		//////////////////////////////////////
		virtual int  QryHisMoney(const ESForeign::TEsHisMoneyQryReqField &req, int &iReqID) = 0;


    };
}

extern "C"
{
    ////////////////////////////////////////
    /// \fn    GetEsunnyForeignApiVersion
    /// \brief 获取API当前版本
    /// \param ESForeign::TEsVersionType version 版本详细信息
    /// \return   void 
    ////////////////////////////////////////
    void  GetEsunnyForeignApiVersion(ESForeign::TEsVersionType version);

    ////////////////////////////////////////
    /// \fn    CreateEsunnyForeignTradeApi
    /// \brief 
    /// \param ESForeign::TEsCertInfoType cert 认证码
    /// \param ESForeign::TEsLogPathType path  日志路径
    /// \param int * pRetCode 错误码，输出参数，需要传入保存错误码的变量地址，其中高16位为保留信息
    ///        低16位为错误码，获取实际错误码需要对高16位清零
    /// \return   ESForeign::IEsunnyTradeApi*  返回交易API实例的指针，如果认证失败，返回NULL，错误码保存在
    ///           pRetCode指向内容的低16位
    ////////////////////////////////////////
    ESForeign::IEsunnyTradeApi*  CreateEsunnyForeignTradeApi(ESForeign::TEsCertInfoType cert, int* pRetCode, 
		ESForeign::TEsLogPathType path, ESForeign::TEsAppIDType appID);

    ////////////////////////////////////////
    /// \fn    DelEsunnyForeignTradeApi
    /// \brief 通过CreateEsunnyForeignTradeApi创建的交易实例通过本接口释放资源
    /// \param ESForeign::IEsunnyTradeApi * pAPI
    /// \return   void 
    ////////////////////////////////////////
    void  DelEsunnyForeignTradeApi(ESForeign::IEsunnyTradeApi* pAPI);
}


#endif
