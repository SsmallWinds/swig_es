#ifndef _ESUNNY_FOREIGN_TRADE_API_
#define _ESUNNY_FOREIGN_TRADE_API_

#include "EsForeignApiStruct.h"
#ifdef linux
#define __cdecl
#endif

namespace ESForeign
{
    //�������ݴ���Ļص������࣬�������ݵ��ﱾ��ʱ��API��ص������ж�Ӧ�Ľӿ�
    //�ص����������������Բ���
    //OnRsp��ͷ�ĺ���Ϊ����������Ӧ��Ӧ��OnRtn��ͷ�ĺ���Ϊ������������������
    class IEsunnyTradeSpi
    {
    public:
        ////////////////////////////////////////
        /// \fn    ~IEsunnyTradeSpi
        /// \brief �����࣬��Ҫ����
        /// \return   
        ////////////////////////////////////////
        virtual ~IEsunnyTradeSpi() {};

        ////////////////////////////////////////
        /// \fn    OnOpen
        /// \brief ���������������ʱ����
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnOpen() = 0;

        ////////////////////////////////////////
        /// \fn    OnClose
        /// \brief ��������Ͽ�����ʱ����
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnClose() = 0;

        ////////////////////////////////////////
        /// \fn    OnLogin
        /// \brief ����Login��½�ɹ�ʱ�յ���������½��Ӧ����
        /// \param const TEsLoginRspField & rsp
        /// \param int iReqID
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnLogin(const TEsLoginRspField* rsp, int errCode, const int iReqID) = 0;



		////////////////////////////////////////
		/// \fn    OnRtnContact
		/// \brief ����Login��½�������Ҫ���ж�̬��֤���򷵻���Ҫ���͵�������ߵ绰
		/// \param const TContactInfoType & rsp
		/// \param TEsIsLastType islast
		/// \param int errCode
		/// \return   void 
		////////////////////////////////////////
		virtual void  OnRtnContact(const TContactInfoType *rsp, TEsIsLastType islast, int errCode) = 0;


		////////////////////////////////////////
		/// \fn    OnRspRequestVertificateCode
		/// \brief ����������֤��֮���Ӧ��
		/// \param const TContactInfoType & rsp
		/// \param int errCode
		/// \param int iReqID
		/// \return   void 
		////////////////////////////////////////
		virtual void  OnRspRequestVertificateCode(const TEsRequestVertificateCodeRsp *rsp, int errCode,const int iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    OnInitFinished
        /// \brief ����Login�ɹ����յ�OnLoginӦ��ɹ����յ���ʼ���������
        ///        ���е�ҵ�������Ҫ�ڱ���ӦerrCodeΪ0���ɹ�����ɽ���
        /// \param int errCode �����룬0-�ɹ�������ֵ-�����ԭ�����
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnInitFinished(int errCode) = 0;

        ////////////////////////////////////////
        /// \fn    OnLogOut
        /// \brief �յ��ǳ�Ӧ�����
        /// \param int errCode
        /// \param const int iReqID
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnLogOut(int errCode, const int iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    OnRspSetPassword
        /// \brief  �޸Ŀͻ�����ʱӦ�𣬷�����Ϣ�����޸�������ϸ����
        /// \param const TEsClientPasswordModifyRspField & rsp
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRspSetPassword(const TEsClientPasswordModifyRspField* rsp, int errCode, const int iReqID){};

        ////////////////////////////////////////
        /// \fn    OnRspSetOperPassword
        /// \brief �޸Ĳ���Ա����ʱӦ�𣬷�����Ϣ�����޸�������ϸ����
        /// \param const TEsOperatorPasswordModifyRspField & rsp
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRspSetOperPassword(const TEsOperatorPasswordModifyRspField* rsp, int errCode, const int iReqID) {};

        ////////////////////////////////////////
        /// \fn    OnQryMoney
        /// \brief �ʽ��ѯӦ��
        /// \param TEsMoneyQryRspField * rsp ��ѯ���ʱ��ָ��Ϊ�գ�δ���ʱ������ѯ���
        /// \param TEsIsLastType islast ָʾ�Ƿ��ѯ��ɣ����ʱrspָ��Ϊ��
        /// \param const int iReqID ��Ӧ���������ID
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnQryMoney(const TEsMoneyQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};
        
        ////////////////////////////////////////
        /// \fn    OnRtnMoney
        /// \brief �ʽ�仯����֪ͨ
        /// \param TEsMoneyChgNoticeField & rsp �ʽ�仯��ϸ��Ϣ
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRtnMoney(const TEsMoneyChgNoticeField& rsp) {};

        ////////////////////////////////////////
        /// \fn    OnRspCashOperQry
        /// \brief ��������ѯӦ��
        /// \param TEsCashOperRspField * rsp��ѯ���ʱ��ָ��Ϊ�գ�δ���ʱ������ѯ���
        /// \param TEsIsLastType islast ָʾ�Ƿ��ѯ��ɣ����ʱrspָ��Ϊ��
        /// \param const int iReqID ��Ӧ���������ID
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRspCashOperQry(const TEsCashOperQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};
        
        ////////////////////////////////////////
        /// \fn    OnRspCashOper
        /// \brief ����������Ӧ��
        /// \param TEsCashOperRspField * rsp ������������ϸ���
		/// \param const int iReqID ��Ӧ���������ID
		/// \note   ��Ҫ�ڴ˺�����ͬ��ִ�з�ǿ�Ƴ����CashCheck
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRspCashOper(const TEsCashOperRspField* rsp, int errCode, const int iReqID) {};
        
        ////////////////////////////////////////
        /// \fn    OnRtnCashOper
		/// \brief ��������������֪ͨ
		/// \param TEsCashOperNoticeField & rsp ������������ϸ��Ϣ
		/// \return   void 
		/// \note   ��Ҫ�ڴ˺�����ͬ��ִ�з�ǿ�Ƴ����CashCheck
        ////////////////////////////////////////
        virtual void  OnRtnCashOper(const TEsCashOperNoticeField& rsp) {};
        
        ////////////////////////////////////////
        /// \fn    OnRspCashCheck
        /// \brief ����������Ӧ��
        /// \param TEsCashCheckRspField * rsp �������˵���ϸ���
        /// \param const int iReqID ��Ӧ���������ID
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRspCashCheck(const TEsCashCheckRspField* rsp, int errCode, const int iReqID) {};
        
        ////////////////////////////////////////
        /// \fn    OnRtnCashCheck
        /// \brief ��������������֪ͨ
        /// \param TEsCashCheckNoticeField & rsp �������˵���ϸ��Ϣ
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRtnCashCheck(const TEsCashCheckNoticeField& rsp) {};

        ////////////////////////////////////////
        /// \fn    OnRspCashAdjustQry
        /// \brief �ʽ������ѯӦ��
        /// \param TEsAdjustOperRspField * rsp ��ѯ�������ѯ���ʱ��ָ��Ϊ��
        /// \param TEsIsLastType islast ָʾ�Ƿ��ѯ��ɣ����ʱrspָ��Ϊ��
        /// \param const int iReqID ��Ӧ���������ID
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRspCashAdjustQry(const TEsAdjustQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};

        ////////////////////////////////////////
        /// \fn    OnRspOrderInsert
        /// \brief ���������Ӧ��
        /// \param TEsOrderInsertRspField & rsp �����������ϸ������᷵��ί�кż����غ�
        /// \param const int iReqID ��Ӧ���������ID
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRspOrderInsert(const TEsOrderInsertRspField* rsp, int errCode, const int iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    OnRspOrderModify
        /// \brief �ĵ������Ӧ�𣬳���ʱ���յ���Ӧ��
        /// \param TEsOrderModifyRspField & rsp
        /// \param const int iReqID ��Ӧ���������ID
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRspOrderModify(const TEsOrderModifyRspField* rsp, int errCode, const int iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    OnRspOrderDelete
        /// \brief ���������Ӧ�𣬳���ʱ���յ���Ӧ��
        /// \param TEsOrderDeleteRspField & rsp
        /// \param const int iReqID ��Ӧ���������ID
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRspOrderDelete(const TEsOrderDeleteRspField* rsp, int errCode, const int iReqID) = 0;
        
        ////////////////////////////////////////
        /// \fn    OnRspQryOrder
        /// \brief ί�в�ѯӦ��
        /// \param TEsOrderDataQryRspField * rsp ί�в�ѯ�������ѯ���ʱ��ָ��Ϊ��
        /// \param TEsIsLastType islast ָʾ�Ƿ��ѯ��ɣ����ʱrspָ��Ϊ��
        /// \param const int iReqID ��Ӧ���������ID
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRspQryOrder(const TEsOrderDataQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};
        
        ////////////////////////////////////////
        /// \fn    OnRspHistOrderQry
        /// \brief ��ʷί�в�ѯӦ��
        /// \param TEsHisOrderQryRspField * rsp ��ʷί�в�ѯ�������ѯ���ʱ��ָ��Ϊ��
        /// \param TEsIsLastType islast ָʾ�Ƿ��ѯ��ɣ����ʱrspָ��Ϊ��
        /// \param const int iReqID ��Ӧ���������ID
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRspHistOrderQry(const TEsHisOrderQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};
        
        ////////////////////////////////////////
        /// \fn    OnRtnOrderState
        /// \brief ί�б仯֪ͨ��ί��״̬�仯ʱ�ص�
        /// \param TEsOrderStateNoticeField & rsp ί����ϸ����
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRtnOrderState(const TEsOrderStateNoticeField& rsp) = 0;
        
        ////////////////////////////////////////
        /// \fn    OnRtnOrderInfo
        /// \brief ί����Ϣ�仯֪ͨ��ί����Ϣ�仯ʱ�ص�
        /// \param TEsOrderInfoNoticeField & rsp ί����Ϣ��ϸ����
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRtnOrderInfo(const TEsOrderInfoNoticeField& rsp) = 0;

        ////////////////////////////////////////
        /// \fn    OnRspMatchQry
        /// \brief  �ɽ���ѯӦ��
        /// \param TEsMatchDataQryRspField * rsp �ɽ���ѯ�������ѯ���ʱ��ָ��Ϊ��
        /// \param TEsIsLastType islast ָʾ�Ƿ��ѯ��ɣ����ʱrspָ��Ϊ��
        /// \param const int iReqID ��Ӧ���������ID
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRspMatchQry(const TEsMatchDataQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};

        ////////////////////////////////////////
        /// \fn    OnRtnMatchState
        /// \brief �ɽ��仯����֪ͨ
        /// \param TEsMatchStateNoticeField & rsp �ɽ���ϸ����
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRtnMatchState(const TEsMatchStateNoticeField& rsp) = 0;

        ////////////////////////////////////////
        /// \fn    OnRtnMatchInfo
        /// \brief �ɽ���Ϣ�仯����֪ͨ
        /// \param TEsMatchInfoNoticeField & rsp �ɽ���Ϣ��ϸ����
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRtnMatchInfo(const TEsMatchInfoNoticeField& rsp) = 0;

        ////////////////////////////////////////
        /// \fn    OnRspHistMatchQry
        /// \brief ��ʷ�ɽ���ѯӦ��
        /// \param TEsHisMatchQryRspField * rsp ��ʷ�ɽ���ѯ�������ѯ���ʱ��ָ��Ϊ��
        /// \param TEsIsLastType islast ָʾ�Ƿ��ѯ��ɣ����ʱrspָ��Ϊ��
        /// \param const int iReqID ��Ӧ���������ID
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRspHistMatchQry(const TEsHisMatchQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};

        ////////////////////////////////////////
        /// \fn    OnQryHold
        /// \brief �ֲֲ�ѯӦ��
        /// \param TEsHoldQryRspField * rsp �ֲֲ�ѯ�������ѯ���ʱ��ָ��Ϊ��
        /// \param TEsIsLastType islast ָʾ�Ƿ��ѯ��ɣ����ʱrspָ��Ϊ��
        /// \param const int iReqID ��Ӧ���������ID
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnQryHold(const TEsHoldQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};
        
        ////////////////////////////////////////
        /// \fn    OnRtnHold
        /// \brief �ֱֲ仯����֪ͨ����ʱδ��
        /// \param TEsHoldQryRspField & rsp �ֲ���ϸ��Ϣ
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRtnHold(const TEsHoldQryRspField& rsp) {};

        ////////////////////////////////////////
        /// \fn    OnQryExchangeState
        /// \brief �г�״̬��ѯӦ��
        /// \param TEsExchangeQryRspField * rsp �г�״̬��ϸ��Ϣ����ѯ���ʱ��ָ��Ϊ��
        /// \param TEsIsLastType islast ָʾ�Ƿ��ѯ��ɣ����ʱrspָ��Ϊ��
        /// \param const int iReqID ��Ӧ���������ID
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnQryExchangeState(const TEsExchangeQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};

        ////////////////////////////////////////
        /// \fn    OnRtnExchangeState
        /// \brief �г�״̬�������֪ͨ
        /// \param TEsExchangeQryRspField & rsp �г�״̬��ϸ��Ϣ
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRtnExchangeState(const TEsExchangeStateModifyNoticeField& rsp) = 0;

        ////////////////////////////////////////
        /// \fn    OnQryCommodity
        /// \brief ��Ʒ��ѯӦ��
        /// \param TEsCommodityQryRspField * rsp ��Ʒ��ϸ��Ϣ����ѯ���ʱ��ָ��Ϊ��
        /// \param TEsIsLastType islast ָʾ�Ƿ��ѯ��ɣ����ʱrspָ��Ϊ��
        /// \param const int iReqID ��Ӧ���������ID
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnQryCommodity(const TEsCommodityQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};

        ////////////////////////////////////////
        /// \fn    OnQryContract
        /// \brief ��Լ��ѯӦ��
        /// \param TEsContractQryRspField * rsp ��Լ��ϸ��Ϣ����ѯ���ʱ��ָ��Ϊ��
        /// \param TEsIsLastType islast ָʾ�Ƿ��ѯ��ɣ����ʱrspָ��Ϊ��
        /// \param const int iReqID ��Ӧ���������ID
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnQryContract(const TEsContractQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};

        ////////////////////////////////////////
        /// \fn    OnQryClient
        /// \brief ����Ա�����ͻ���Ϣ��ѯӦ��
        /// \param TEsOperatorClientQryRspField * rsp �����ͻ���ϸ��Ϣ����ѯ���ʱ��ָ��Ϊ��
        /// \param TEsIsLastType islast ָʾ�Ƿ��ѯ��ɣ����ʱrspָ��Ϊ��
        /// \param const int iReqID ��Ӧ���������ID
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnQryClient(const TEsOperatorClientQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};


        ////////////////////////////////////////
        /// \fn    OnRspHistCashOperQry
        /// \brief ��ʷ��������ѯӦ��
        /// \param const TEsHisCashQryRspField * rsp
        /// \param TEsIsLastType islast
        /// \param int errCode
        /// \param const int iReqID
        /// \return void 
        ////////////////////////////////////////
        virtual void  OnRspHistCashOperQry(const TEsHisCashOperQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};

        ////////////////////////////////////////
        /// \fn    OnRspCashAdjustQry
        /// \brief ��ʷ�ʽ������ѯӦ��
        /// \param TEsAdjustOperRspField * rsp ��ѯ�������ѯ���ʱ��ָ��Ϊ��
        /// \param TEsIsLastType islast ָʾ�Ƿ��ѯ��ɣ����ʱrspָ��Ϊ��
        /// \param const int iReqID ��Ӧ���������ID
        /// \return   void 
        ////////////////////////////////////////
        virtual void  OnRspHistCashAdjustQry(const TEsHisAdjustQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};

        ////////////////////////////////////////
        /// \fn    OnRspAuthClient
        /// \brief �û�������֤����Ӧ��
        /// \param const TEsLoginRspField * rsp
        /// \param int errCode
        /// \param const int iReqID
        /// \return void 
        ////////////////////////////////////////
        virtual void  OnRspAuthClient(const TEsClientPasswordAuthRspField* rsp, int errCode, const int iReqID) {};

        ////////////////////////////////////////
        /// \fn    OnRspQryCurrency
        /// \brief ��ѯ���ұ�����ϢӦ��
        /// \param const TEsCurrencyQryRspField * rsp
        /// \param int errCode
        /// \param const int iReqID
        /// \return void 
        ////////////////////////////////////////
        virtual void  OnRspQryCurrency(const TEsCurrencyQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};

        ////////////////////////////////////////
        /// \fn    OnRtnExchangeRateMod
        /// \brief ���ֻ��ʱ仯֪ͨ
        /// \param const TEsCurrencyQryRspField * rsp
        /// \param TEsIsLastType islast
        /// \param int errCode
        /// \param const int iReqID
        /// \return void 
        ////////////////////////////////////////
        virtual void  OnRtnExchangeRateMod(const TEsExchangeRateModifyNoticeField& rsp) {};

        ////////////////////////////////////////
        /// \fn    OnRtnOrderRemove
        /// \brief ί��ɾ��֪ͨ
        /// \param const TEsOrderRemoveNoticeField & rsp
        /// \return void 
        ////////////////////////////////////////
        virtual void  OnRtnOrderRemove(const TEsOrderRemoveNoticeField& rsp) {};

        ////////////////////////////////////////
        /// \fn    OnRtnMatchRemove
        /// \brief �ɽ�ɾ��֪ͨ
        /// \param const TEsMatchRemoveNoticeField & rsp
        /// \return void 
        ////////////////////////////////////////
        virtual void  OnRtnMatchRemove(const TEsMatchRemoveNoticeField& rsp) {};

        ////////////////////////////////////////
        /// \fn    OnRtnCommodityState
        /// \brief ��Ʒ״̬�仯֪ͨ
        /// \param const TEsCommodityStateModNotice & rsp
        /// \return void 
        ////////////////////////////////////////
        virtual void  OnRtnCommodityState(const TEsCommodityStateModNoticeField& rsp) {};

		////////////////////////////////////////
		/// \fn    OnRtnContractAdd
		/// \brief ��Լ���֪ͨ
		/// \param const TEsContractAddNoticeField & rsp
		/// \return void 
		////////////////////////////////////////
		virtual void  OnRtnContractAdd(const TEsContractAddNoticeField& rsp) {};
		
		////////////////////////////////////////
		/// \fn    OnRspQryMonitorEvent
		/// \brief ��ѯ����¼�Ӧ��
		/// \param const TEsMonitorEventQryRspField * rsp
		/// \param int errCode
		/// \param const int iReqID
		/// \return void 
		////////////////////////////////////////
		virtual void  OnRspQryMonitorEvent(const TEsMonitorEventQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};

		////////////////////////////////////////
		/// \fn    OnRtnMonitorEvent
		/// \brief ����¼�֪ͨ
		/// \param const TEsMonitorEventNoticeField & rsp
		/// \return void 
		////////////////////////////////////////
		virtual void  OnRtnMonitorEvent(const TEsMonitorEventNoticeField& rsp) {};

		////////////////////////////////////////
		/// \fn    OnRspMarketOrderInsert
		/// \brief �۽����������µ�Ӧ��
		/// \param const TEsHKMarketOrderRsp * rsp
		/// \param int errCode
		/// \param const int iReqID
		/// \return void 
		////////////////////////////////////////
		virtual void  OnRspHKMarketOrder(const TEsHKMarketOrderRsp* rsp,int errCode,const int iReqID) {};

		////////////////////////////////////////
		/// \fn    OnRspQryClientCountRent
		/// \brief ��ѯ�������Ӧ��.
		/// \param const TClientCountRentQryRsp * rsp
		/// \param int errCode
		/// \param const int iReqID
		/// \return void 
		////////////////////////////////////////
		virtual void  OnRspQryClientCountRent(const TClientCountRentQryRsp* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};
		////////////////////////////////////////
		/// \fn    OnRspQryLmeContract
		/// \brief ��ѯLME������Ӧ��.
		/// \param const TClientCountRentQryRsp * rsp
		/// \param int errCode
		/// \param const int iReqID
		/// \return void 
		////////////////////////////////////////
		virtual void  OnRspQryLmeContract(const TEsQryLmeContractRspField *rsp, int errCode, const int iReqID){};
		////////////////////////////////////////
		/// \fn    OnRtnLmeContract
		/// \brief LME������֪ͨ.
		/// \param const TLmeContractNotice * rsp
		/// \return void 
		////////////////////////////////////////
		virtual void  OnRtnLmeContract(const TEsLmeContractNotice *info){};
		////////////////////////////////////////
		/// \fn    OnRspQryHisHold
		/// \brief ��ѯ��ʷ�ֲ�Ӧ��.
		/// \param const THisHoldQryRsp * rsp
		/// \param int errCode
		/// \param const int iReqID
		/// \return void 
		////////////////////////////////////////
		virtual void  OnRspQryHisHold(const TEsHisHoldQryRspField* rsp, TEsIsLastType islast, int errCode, const int iReqID) {};
		////////////////////////////////////////
		/// \fn    OnRspQryHisMoney
		/// \brief ��ѯ��ʷ�ʽ�Ӧ��.
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
        /// \brief ������������ͨ��IEsunnyFeTradeApiָ���ܹ�ɾ������APIʵ����
        /// ɾ������APIʵ��ʱ���Ƽ�ʹ��Free����
        /// \return   
        ////////////////////////////////////////
        virtual ~IEsunnyTradeApi(){};

        ////////////////////////////////////////
        /// \fn    SetSpi
        /// \brief ���ûص����ݽӿڣ���֤APIͨ������Ҫ���ñ��ӿ����ûص�������
        /// \param IEsunnyTradeSpi * spi
        /// \return   void 
        ////////////////////////////////////////
        virtual void  SetSpi(IEsunnyTradeSpi* spi) = 0;

        ////////////////////////////////////////
        /// \fn    Free
        /// \brief �ͷŵ�ǰapi�Ự
        /// \return   void 
        ////////////////////////////////////////
        virtual void  Free() = 0;

        ////////////////////////////////////////
        /// \fn    GetErrcodeDesc
        /// \brief ��ȡ���������������(���ֽڱ���)
        /// \param int iErrcode
        /// \return   const char* 
        ////////////////////////////////////////
        virtual const char*  GetErrcodeDesc(int iErrcode) = 0;

        ////////////////////////////////////////
        /// \fn    Open
        /// \brief ���ӽ��׷����������سɹ�ֻ�����ɹ��������������Ƿ���������Ҫ
        /// ����IsOpen����
        /// \param TEsAddressField & addr
        /// \return   bool 
        ////////////////////////////////////////
        virtual bool  Open(const TEsAddressField& addr) = 0;

        ////////////////////////////////////////
        /// \fn    Close
        /// \brief �رս��׷���������
        /// \return   void 
        ////////////////////////////////////////
        virtual void  Close() = 0;

        ////////////////////////////////////////
        /// \fn    IsOpen
        /// \brief ��ȡ�Ƿ��뽻�׷�������������
        /// \return   bool 
        ////////////////////////////////////////
        virtual bool  IsOpen() = 0;

        ////////////////////////////////////////
        /// \fn    Login
        /// \brief ���͵�¼������ʱ֧�ֵ��ͻ���½
        /// \param TEsLoginReq & req
        /// \return   int 
        ////////////////////////////////////////
        virtual int  Login(const TEsLoginReqField& req, int& iReqID) = 0;

		////////////////////////////////////////
		/// \fn    RequestVertificateCode
		/// \brief ���Ͷ�����֤��Ȩ��
		/// \param TEsLoginReq & req
		/// \return   int 
		////////////////////////////////////////
		virtual int  RequestVertificateCode(const TEsRequestVertificateCodeReq CertificateCode, int& iReqID) = 0;

		////////////////////////////////////////
		/// \fn    SetVertificateCode
		/// \brief ���Ͷ�����֤��Ȩ��
		/// \param TEsLoginReq & req
		/// \return   int 
		////////////////////////////////////////
		virtual int  SetVertificateCode(const TVertificateCodeType CertificateCode, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    LogOut
        /// \brief �����˳�����
        /// \return   int 
        ////////////////////////////////////////
        virtual int  LogOut(int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    SetPassword
        /// \brief �޸Ŀͻ�����
        /// \param TEsSetPassReqField & req
        /// \return   int 
        ////////////////////////////////////////
        virtual int  SetPassword(const TEsClientPasswordModifyReqField& req, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    SetOperPassword
        /// \brief �޸Ĳ���Ա���룬��ʱδ��
        /// \param const TEsOperatorPasswordModifyReqField & req
        /// \param int & iReqID
        /// \return   int 
        ////////////////////////////////////////
        virtual int  SetOperPassword(const TEsOperatorPasswordModifyReqField& req, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryClients
        /// \brief ��ѯ����Ա�����ͻ�����ʱδ��
        /// \param const TOperatorClientQryReq & qryClients
        /// \return   int 
        ////////////////////////////////////////
        virtual int  QryClients(const TEsOperatorClientQryReqField& qryClients, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryMoney
        /// \brief ��ѯ�ͻ��ʽ�
        /// \param const TMoneyQryReq & qryMoney
        /// \return   int 
        ////////////////////////////////////////
        virtual int  QryMoney(const TEsMoneyQryReqField& qryMoney, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryOrder
        /// \brief ��ѯ�ͻ�ί�У���ѯ�������� ������0
        /// \param const TOrderQryReq & qryOrder
        /// \return   int 
        ////////////////////////////////////////
        virtual int  QryOrder(const TEsOrderQryReqField& qryOrder, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryMatch
        /// \brief ��ѯ�ͻ��ɽ�
        /// \param const TMatchQryReq & qryMatch
        /// \return   int 
        ////////////////////////////////////////
        virtual int  QryMatch(const TMatchQryReqField& qryMatch, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryHold
        /// \brief ��ѯ�ֲ�
        /// \param const THoldQryReq & qryHold
        /// \return   int 
        ////////////////////////////////////////
        virtual int  QryHold(const TEsHoldQryReqField& qryHold, int& iReqID) = 0;


        ////////////////////////////////////////
        /// \fn    QryExchangeState
        /// \brief ��ѯ������״̬
        /// \param const TExchangeQryReq & qryExg
        /// \return   int 
        ////////////////////////////////////////
        virtual int  QryExchangeState(const TEsExchangeQryReqField& qryExg, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryCommodity
        /// \brief ��ѯ������Ʒ
        /// \param const TCommodityQryReq & qryCmdy
        /// \return   int 
        ////////////////////////////////////////
        virtual int  QryCommodity(const TEsCommodityQryReqField& qryCmdy, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryContract
        /// \brief ��ѯ��Լ
        /// \param const TContractQryReq & qryCntr
        /// \return   int 
        ////////////////////////////////////////
        virtual int  QryContract(const TEsContractQryReqField& qryCntr, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    OrderInsert
        /// \brief ��������
        /// \param TEsOrderInsertReqField & req
        /// \param int * pReqID
        /// \return   int 
        ////////////////////////////////////////
        virtual int  OrderInsert(const TEsOrderInsertReqField& req, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    OrderModify
        /// \brief �ĵ�����
        /// \param TEsOrderModifyReqField & req
        /// \return   int 
        ////////////////////////////////////////
        virtual int  OrderModify(const TEsOrderModifyReqField& req, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    OrderDelete
        /// \brief ��������
        /// \param TEsOrderDeleteReqField & req
        /// \return   int 
        ////////////////////////////////////////
        virtual int  OrderDelete(const TEsOrderDeleteReqField& req, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryHistOrder
        /// \brief ��ʷί�в�ѯ
        /// \param TEsHisOrderQryReqField & req
        /// \param int & iReqID
        /// \return   int 
        ////////////////////////////////////////
        virtual int  QryHistOrder(const TEsHisOrderQryReqField& req, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryHistMatch
        /// \brief ��ʷ�ɽ���ѯ
        /// \param TEsHisMatchQryReqField & req
        /// \param int & iReqID
        /// \return   int 
        ////////////////////////////////////////
        virtual int  QryHistMatch(const TEsHisMatchQryReqField& req, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryCashOper
        /// \brief ��������ѯ
        /// \param TEsCashOperQryReqField & req
        /// \param int & iReqID
        /// \return   int 
        ////////////////////////////////////////
        virtual int  QryCashOper(const TEsCashOperQryReqField& req, int& iReqID) = 0;
        
        ////////////////////////////////////////
        /// \fn    CashOper
        /// \brief ��������������
        /// \param TEsCashOperReqField & req
        /// \param int & iReqID
        /// \return   int 
        ////////////////////////////////////////
        virtual int  CashOper(const TEsCashOperReqField& req, int& iReqID) = 0;
        
        ////////////////////////////////////////
        /// \fn    CashCheck
        /// \brief ��������������
        /// \param TEsCashCheckReqField & req
        /// \param int & iReqID
        /// \return   int 
        ////////////////////////////////////////
        virtual int  CashCheck(const TEsCashCheckReqField& req, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryCachAdjust
        /// \brief �ʽ������ѯ
        /// \param TEsAdjustQryReqField & req
        /// \param int & iReqID
        /// \return   int 
        ////////////////////////////////////////
        virtual int  QryCachAdjust(const TEsAdjustQryReqField& req, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryHistCashOper
        /// \brief ��ʷ��������ѯ
        /// \param const TEsHisCashQryReqField & req
        /// \param int & iReqID
        /// \return int 
        ////////////////////////////////////////
        virtual int  QryHistCashOper(const TEsHisCashOperQryReqField& req, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryHistCachAdjust
        /// \brief ��ʷ�ʽ������ѯ
        /// \param const THisAdjustQryReq & req
        /// \param int & iReqID
        /// \return int 
        ////////////////////////////////////////
        virtual int  QryHistCachAdjust(const TEsHisAdjustQryReqField& req, int& iReqID) = 0;     

        ////////////////////////////////////////
        /// \fn    AuthUserPassword
        /// \brief ��֤�û�������
        /// \param const TEsLoginReqField & req
        /// \param int & iReqID
        /// \return int 
        ////////////////////////////////////////
        virtual int  AuthClient(const TEsClientPasswordAuthReqField& req, int& iReqID) = 0;

        ////////////////////////////////////////
        /// \fn    QryCurrency
        /// \brief ��ѯ���ұ�����Ϣ
        /// \param const TEsCurrencyQryReqField & req
        /// \param int & iReqID
        /// \return int 
        ////////////////////////////////////////
		virtual int  QryCurrency(const TEsCurrencyQryReqField& req, int& iReqID) = 0;

		////////////////////////////////////////
		/// \fn    GetCertCodeExpireDate
		/// \brief ��ȡ��֤���������
		/// \param TDateType & expireDate
		/// \return int 
		////////////////////////////////////////
		virtual int  GetCertCodeExpireDate(TDateType& expireDate) = 0;

		////////////////////////////////////////
		/// \fn    QryMonitorEvent
		/// \brief ��ѯ����¼�
		/// \param const TEsMonitorEventQryReqField & req
		/// \param int & iReqID
		/// \return int 
		////////////////////////////////////////
		virtual int  QryMonitorEvent(const TEsMonitorEventQryReqField& req, int& iReqID) = 0;

		////////////////////////////////////////
		/// \fn    HKMarketOrderInsert
		/// \brief �¸۽��������̱���
		/// \param const THKMarketOrderReq & req
		/// \param int & iReqID
		/// \return int 
		////////////////////////////////////////
		virtual int  HKMarketOrderOperator(const ESForeign::TEsHKMarketOrderReq& req, int& iReqID) = 0;

		////////////////////////////////////////
		/// \fn QryCountRent
		/// \brief �ͻ����������ѯ
		/// \param const TClientCountRentReq &req
		/// \param int &iReqID
		///\return int 
		///////////////////////////////////////
		virtual int  QryCountRent(const ESForeign::TClientCountRentQryReq &req, int & iReqID) = 0;
		///////////////////////////////////////
		/// \fn QryLmeContract
		/// \brief LME�����ղ�ѯ
		/// \param int &iReqID
		/// \return int 
		//////////////////////////////////////
		virtual int  QryLmeContract(int &iReqID) = 0;

		//////////////////////////////////////
		/// \fn QryHisHold
		/// \brief ��ѯ��ʷ�ֲ�
		/// \param const THisHoldQryReq &req
		/// \param int &iReqID
		/// \return int 
		/////////////////////////////////////
		virtual int  QryHisHold(const ESForeign::TEsHisHoldQryReqField &req, int &iReqID) = 0;

		//////////////////////////////////////
		/// \fn QryHisHold
		/// \brief ��ѯ��ʷ�ʽ�.
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
    /// \brief ��ȡAPI��ǰ�汾
    /// \param ESForeign::TEsVersionType version �汾��ϸ��Ϣ
    /// \return   void 
    ////////////////////////////////////////
    void  GetEsunnyForeignApiVersion(ESForeign::TEsVersionType version);

    ////////////////////////////////////////
    /// \fn    CreateEsunnyForeignTradeApi
    /// \brief 
    /// \param ESForeign::TEsCertInfoType cert ��֤��
    /// \param ESForeign::TEsLogPathType path  ��־·��
    /// \param int * pRetCode �����룬�����������Ҫ���뱣�������ı�����ַ�����и�16λΪ������Ϣ
    ///        ��16λΪ�����룬��ȡʵ�ʴ�������Ҫ�Ը�16λ����
    /// \return   ESForeign::IEsunnyTradeApi*  ���ؽ���APIʵ����ָ�룬�����֤ʧ�ܣ�����NULL�������뱣����
    ///           pRetCodeָ�����ݵĵ�16λ
    ////////////////////////////////////////
    ESForeign::IEsunnyTradeApi*  CreateEsunnyForeignTradeApi(ESForeign::TEsCertInfoType cert, int* pRetCode, 
		ESForeign::TEsLogPathType path, ESForeign::TEsAppIDType appID);

    ////////////////////////////////////////
    /// \fn    DelEsunnyForeignTradeApi
    /// \brief ͨ��CreateEsunnyForeignTradeApi�����Ľ���ʵ��ͨ�����ӿ��ͷ���Դ
    /// \param ESForeign::IEsunnyTradeApi * pAPI
    /// \return   void 
    ////////////////////////////////////////
    void  DelEsunnyForeignTradeApi(ESForeign::IEsunnyTradeApi* pAPI);
}


#endif
