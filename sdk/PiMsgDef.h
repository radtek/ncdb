#pragma once
#include <windows.h>
#include <tchar.h>
//������Ϣ����
#define IDSTR(MsgID) MsgID,_T(#MsgID)

typedef struct
{
	DWORD dwMsg;
	LPCTSTR szMsgText;
	LPCTSTR szNote;
} t_MSGNOTE;


static t_MSGNOTE messagesnote[] =
{
	IDSTR(WM_NULL), _T("����Ϣ,�ɼ������Ƿ�����Ӧ��"),
	IDSTR(WM_CREATE), _T("�½�һ������"),
	IDSTR(WM_DESTROY), _T("����һ������"),
	//IDSTR(0x0004),_T(""),
	IDSTR(WM_MOVE), _T("�ƶ�һ������"),
	IDSTR(WM_SIZE), _T("�ı�һ�����ڵĴ�С"),
	IDSTR(WM_ACTIVATE), _T("һ�����ڱ������ʧȥ����״̬"),
	IDSTR(WM_SETFOCUS), _T("������ת��һ������"),
	IDSTR(WM_KILLFOCUS), _T("ʹһ������ʧȥ����"),
	IDSTR(0x0009),_T(""),
	IDSTR(WM_ENABLE), _T("ʹһ�����ڴ��ڿ���״̬"),
	IDSTR(WM_SETREDRAW), _T("���ô����Ƿ����ػ�"),
	IDSTR(WM_SETTEXT), _T("����һ�����ڵ��ı�"),
	IDSTR(WM_GETTEXT), _T("���ƴ��ڵ��ı���������"),
	IDSTR(WM_GETTEXTLENGTH), _T("�õ����ڵ��ı�����(����������)"),
	IDSTR(WM_PAINT), _T("�����ػ�"),
	IDSTR(WM_CLOSE), _T("�û��رմ���ʱ�ᷢ�ͱ���Ϣ,�����Żᷢ��WM_DESTROY��Ϣ"),
	IDSTR(WM_QUERYENDSESSION), _T("�ػ���ע��ʱϵͳ�ᰴ���ȼ��������̷���WM_QUERYENDSESSION,����Ӧ�ó���Ҫ�ػ���ע����"),
	IDSTR(WM_QUIT), _T("�ر���Ϣѭ���������������"),
	IDSTR(WM_QUERYOPEN), _T("��С���Ĵ��ڼ������ָ���ǰ�Ĵ�Сλ��"),
	IDSTR(WM_ERASEBKGND), _T("��һ�����ڵı������뱻����ʱ����Ϣ�ᱻ����(��:���ڴ�С�ı�ʱ)"),
	IDSTR(WM_SYSCOLORCHANGE), _T("��ϵͳ��ɫ�ı�ʱ,���ͱ���Ϣ�����ж�������"),
	IDSTR(WM_ENDSESSION), _T("�ػ���ע��ʱϵͳ�ᷢ��WM_QUERYENDSESSION��Ϣ,Ȼ�󽫱���Ϣ���͸�Ӧ�ó���,֪ͨ����Ự����"),
	IDSTR(0x0017),_T(""),
	IDSTR(WM_SHOWWINDOW), _T("���ͱ���Ϣ��һ������,�Ա����ػ���ʾ�ô���"),
	IDSTR(0x0019),_T(""),
	IDSTR(WM_WININICHANGE), _T("��д\"win.ini\"ʱ�ᷢ�ͱ���Ϣ�����ж��㴰��,֪ͨ�������̸��ļ��ѱ�����"),
	IDSTR(WM_DEVMODECHANGE), _T("�ı��豸ģʽ����(\"win.ini\")ʱ,��������Ϣ��Ӧ�ó�������³�ʼ�����ǵ��豸ģʽ����"),
	IDSTR(WM_ACTIVATEAPP), _T("���ڽ��̼���״̬�Ķ�,��������Ĵ������ڲ�ͬ��Ӧ�ó��� "),//??
	IDSTR(WM_FONTCHANGE), _T("��ϵͳ��������Դ��仯ʱ���ͱ���Ϣ�����ж�������"),
	IDSTR(WM_TIMECHANGE), _T("��ϵͳ��ʱ��仯ʱ���ͱ���Ϣ�����ж�������"),
	IDSTR(WM_CANCELMODE), _T("���ͱ���Ϣ��ȡ��ĳ�����ڽ��е�ģ̬(����)(����ʾ����),����:����һ��ģ̬����ʱ,�������յ�����Ϣ;����Ϣ�޲���"),
	IDSTR(WM_SETCURSOR), _T("���������ĳ�������ƶ������û������ʱ,�ͻᷢ�ͱ���Ϣ��ĳ������"),
	IDSTR(WM_MOUSEACTIVATE), _T("���������ĳ��δ�������,���û�����������ĳ����ʱ,�ᷢ�ͱ���Ϣ����ǰ����"),
	IDSTR(WM_CHILDACTIVATE), _T("������ڱ������򵱴��ڱ�����ƶ�����С�ı�ʱ,�ᷢ�ͱ���Ϣ��MDI�Ӵ���"),
	IDSTR(WM_QUEUESYNC), _T("����Ϣ�ɻ��ڼ������ѵ��������,ͨ��WH_JOURNALPALYBACK��HOOK���������û�������Ϣ"),
	IDSTR(WM_GETMINMAXINFO), _T("�����ڽ�Ҫ�ı��С��λ��ʱ,��ϵͳ���ͱ���Ϣ������,�û��϶�һ�������ô�С�Ĵ���ʱ��ᷢ������Ϣ"),
	IDSTR(0x0025),_T(""),
	IDSTR(WM_PAINTICON), _T("��һ����С���Ĵ���ͼ�꽫���ػ�ʱ���ͱ���Ϣ"),
	IDSTR(WM_ICONERASEBKGND), _T("����Ϣ���͸�ĳ����С���Ĵ���,�������ڻ�ͼ��ǰ���ı������뱻�ػ�"),
	IDSTR(WM_NEXTDLGCTL), _T("���ͱ���Ϣ��һ���Ի�����򴰿ڹ���,�Ա��ڸ��ؼ������ü��̽���λ��"),
	IDSTR(0x0029),_T(""),
	IDSTR(WM_SPOOLERSTATUS), _T("ÿ����ӡ�����ж����ӻ����һ����ҵʱ�ͻᷢ������Ϣ"),
	IDSTR(WM_DRAWITEM), _T("��ť����Ͽ��б��򡢲˵�����۸ı�ʱ�ᷢ�ͱ���Ϣ����Щ�ؼ���������"),
	IDSTR(WM_MEASUREITEM), _T("��ť����Ͽ��б����б��ؼ����˵������ʱ�ᷢ�ͱ���Ϣ����Щ�ؼ���������"),
	IDSTR(WM_DELETEITEM), _T("���б������Ͽ����ٻ�ͨ��LB_DELETESTRING��LB_RESETCONTENT��CB_DELETESTRING��CB_RESETCONTENT��Ϣɾ��ĳЩ��ʱ,�ᷢ�ͱ���Ϣ����Щ�ؼ���������"),
	IDSTR(WM_VKEYTOITEM), _T("LBS_WANTKEYBOARDINPUT�����б���ᷢ������Ϣ����������,�Ա���ӦWM_KEYDOWN��Ϣ"),
	IDSTR(WM_CHARTOITEM), _T("LBS_WANTKEYBOARDINPUT�����б���ᷢ�ͱ���Ϣ����������,�Ա���ӦWM_CHAR��Ϣ"),
	IDSTR(WM_SETFONT), _T("ָ���ؼ���������"),
	IDSTR(WM_GETFONT), _T("�õ���ǰ�ؼ��������ı����õ�����"),
	IDSTR(WM_SETHOTKEY), _T("Ϊĳ���ڹ���һ���ȼ�"),
	IDSTR(WM_GETHOTKEY), _T("ȷ��ĳ�ȼ���ĳ�����Ƿ������"),
	IDSTR(0x0034),_T(""),
	IDSTR(0x0035),_T(""),
	IDSTR(0x0036),_T(""),
	IDSTR(WM_QUERYDRAGICON), _T("����Ϣ���͸���С���Ĵ���(iconic),���ô��ڽ����ϷŶ��䴰������û�ж���ͼ��,Ӧ�ó����ܷ���һ��ͼ�����ľ�������û��Ϸ�ͼ��ʱϵͳ����ʾ���ͼ�����"),
	IDSTR(0x0038),_T(""),
	IDSTR(WM_COMPAREITEM), _T("�ɷ��ͱ���Ϣ��ȷ����Ͽ�(CBS_SORT)���б���(LBS_SORT)������������λ��"),
	
	IDSTR(WM_COMPACTING), _T("��ʾ�ڴ��Ѿ�������"),
	IDSTR(0x0042),_T(""),
	IDSTR(0x0043),_T(""),
	IDSTR(WM_COMMNOTIFY), _T("Win3.1��,�������¼�����ʱ,ͨѶ�豸������������Ϣ����Ϣ��ϵͳ,ָʾ����������е�״̬"),
	IDSTR(0x0045),_T(""),
	IDSTR(WM_WINDOWPOSCHANGING), _T("����Ϣ�ᷢ�͸���Щ��С��λ��(Z_Order)�����ı�Ĵ���,�Ե���SetWindowPos�������������ڹ�������"),
	IDSTR(WM_WINDOWPOSCHANGED), _T("����Ϣ�ᷢ�͸���Щ��С��λ��(Z_Order)�ѱ��ı�Ĵ���,�Ե���SetWindowPos�������������ڹ�������"),
	IDSTR(WM_POWER), _T("��ϵͳ��Ҫ������ͣ״̬ʱ���ͱ���Ϣ(������16λ��windows)"),
	IDSTR(0x0049),_T(""),
	IDSTR(WM_COPYDATA), _T("��һ��Ӧ�ó��򴫵����ݸ���һ��Ӧ�ó���ʱ���ͱ���Ϣ"),
	IDSTR(WM_CANCELJOURNAL), _T("���û�ȡ��������־����״̬ʱ,���ͱ���Ϣ���Ǹ�Ӧ�ó��򡣸���Ϣʹ�ÿմ��ھ������"),
	IDSTR(0x004C),_T(""),
	IDSTR(0x004D),_T(""),
	IDSTR(WM_NOTIFY), _T("��ĳ�ؼ���ĳ�¼��ѷ�����ÿؼ���õ�һЩ��Ϣʱ,���ͱ���Ϣ���丸��"),
	IDSTR(0x004F),_T(""),
	IDSTR(WM_INPUTLANGCHANGEREQUEST), _T("���û�ͨ���������������ϵ�����ָʾ����ĳ��ݼ����ѡ��ı����뷨ʱϵͳ���򽹵㴰�ڷ��ͱ���Ϣ"),
	IDSTR(WM_INPUTLANGCHANGE), _T("�л����뷨��,ϵͳ�ᷢ�ͱ���Ϣ����Ӱ��Ķ��㴰��"),
	IDSTR(WM_TCARD), _T("�����ѳ�ʼ��windows��������ʱ�ᷢ�ͱ���Ϣ��Ӧ�ó���"),
	IDSTR(WM_HELP), _T("����<F1>��,��ĳ�˵��Ǽ����,�ͷ��ͱ���Ϣ���˴��ڹ����Ĳ˵�;����ͷ��͸��н���Ĵ���;����ǰ��û�н���,�Ͱѱ���Ϣ���͸���ǰ����Ĵ���"),
	IDSTR(WM_USERCHANGED), _T("���û��ѵ�����˳����ͱ���Ϣ�����д���;���û�������˳�ʱϵͳ�����û��ľ���������Ϣ,���û���������ʱϵͳ���Ϸ��ͱ���Ϣ"),
	IDSTR(WM_NOTIFYFORMAT), _T("���ÿؼ����Զ���ؼ����丸��ͨ������Ϣ�жϿؼ���WM_NOTIFY֪ͨ��Ϣ����ʹ��ANSI����UNICODE,ʹ�ñ���Ϣ��ʹĳ���ؼ������ĸ��ؼ�������໥ͨ��"),
	IDSTR(WM_CONTEXTMENU), _T("���û���ĳ�����е���Ҽ��ͷ��ͱ���Ϣ���ô���,�����Ҽ��˵�"),
	IDSTR(WM_STYLECHANGING), _T("������SetWindowLong������Ҫ�ı�һ���������ڵķ��ʱ,���ͱ���Ϣ���Ǹ�����"),
	IDSTR(WM_STYLECHANGED), _T("������SetWindowLong�����ı�һ���������ڵķ���,���ͱ���Ϣ���Ǹ�����"),
	IDSTR(WM_DISPLAYCHANGE), _T("����ʾ���ķֱ��ʸı��,���ͱ���Ϣ�����д���"),
	IDSTR(WM_GETICON), _T("����Ϣ���͸�ĳ������,���ڷ�����ĳ�����й����Ĵ�ͼ���Сͼ��ľ��"),
	IDSTR(WM_SETICON), _T("Ӧ�ó����ͱ���Ϣ��һ���µĴ�ͼ���Сͼ����ĳ���������"),
	IDSTR(WM_NCCREATE), _T("��ĳ�����״α�����ʱ,����Ϣ��WM_CREATE��Ϣ����ǰ����"),
	IDSTR(WM_NCDESTROY), _T("����Ϣ֪ͨĳ����,�ǿͻ�����������"),
	IDSTR(WM_NCCALCSIZE), _T("��ĳ���ڵĿͻ����Ĵ�С��λ���뱻����ʱ���ͱ���Ϣ"),
	IDSTR(WM_NCHITTEST), _T("���û����ڷǿͻ����ƶ���ꡢ��ס���ͷ����ʱ���ͱ���Ϣ(���в���);�����û�б�����,����Ϣ�ڴ��ڵõ����֮�󷢳�,������Ϣ���͵��������Ĵ���"),
	IDSTR(WM_NCPAINT), _T("�����ڿ��(�ǿͻ���)���뱻���ػ�ʱ,Ӧ�ó����ͱ���Ϣ���ô���"),
	IDSTR(WM_NCACTIVATE), _T("����Ϣ���͸�ĳ����,�ڴ��ڵķǿͻ���������ʱ�ػ洰��"),
	IDSTR(WM_GETDLGCODE), _T("���ͱ���Ϣ��ĳ����Ի����������Ŀؼ�,ϵͳ���Ʒ�λ����TAB��ʹ�������ÿؼ�,ͨ����Ӧ����ϢӦ�ó���ɰ�������һ�����������ؼ����ܴ�����"),
	IDSTR(WM_SYNCPAINT), _T("��������ϵ������GUI�߳�ʱ,����Ϣ����ͬ��ˢ��,����Ϣ��ϵͳȷ���Ƿ���"),
	IDSTR(WM_NCMOUSEMOVE), _T("�������ĳ���ڵķǿͻ������ƶ�ʱ,���ͱ���Ϣ���ô���"),
	IDSTR(WM_NCLBUTTONDOWN), _T("�������ĳ���ڵķǿͻ����ڵ�ͬʱ����������,�ᷢ�ͱ���Ϣ"),
	IDSTR(WM_NCLBUTTONUP), _T("���û��ͷ���������ͬʱ�����ĳ���ڵķǿͻ�����ʱ,�ᷢ�ͱ���Ϣ"),
	IDSTR(WM_NCLBUTTONDBLCLK), _T("���û�˫����������ͬʱ�����ĳ���ڵķǿͻ�����ʱ,�ᷢ�ͱ���Ϣ"),
	IDSTR(WM_NCRBUTTONDOWN), _T("���û���������Ҽ���ͬʱ�����ĳ���ڵķǿͻ�����ʱ,�ᷢ�ͱ���Ϣ"),
	IDSTR(WM_NCRBUTTONUP), _T("���û��ͷ�����Ҽ���ͬʱ�����ĳ���ڵķǿͻ�����ʱ,�ᷢ�ͱ���Ϣ"),
	IDSTR(WM_NCRBUTTONDBLCLK), _T("���û�˫������Ҽ���ͬʱ�����ĳ���ڵķǿͻ�����ʱ,�ᷢ�ͱ���Ϣ"),
	IDSTR(WM_NCMBUTTONDOWN), _T("���û���������м���ͬʱ�����ĳ���ڵķǿͻ�����ʱ,�ᷢ�ͱ���Ϣ"),
	IDSTR(WM_NCMBUTTONUP), _T("���û��ͷ�����м���ͬʱ�����ĳ���ڵķǿͻ�����ʱ,�ᷢ�ͱ���Ϣ"),
	IDSTR(WM_NCMBUTTONDBLCLK), _T("���û�˫������м���ͬʱ�����ĳ���ڵķǿͻ�����ʱ,�ᷢ�ͱ���Ϣ"),

	//��������Ϣ
	IDSTR(SBM_SETPOS), _T("���ù������ϻ����λ��"),
	IDSTR(SBM_GETPOS), _T("��ȡ�������ϻ����λ��"),
	IDSTR(SBM_SETRANGE), _T("���ù��������������Сλ��ֵ"),
	IDSTR(SBM_SETRANGEREDRAW), _T("���ù��������������Сλ��ֵ,���ػ������"),
	IDSTR(SBM_GETRANGE), _T("��ȡ���������������Сλ��ֵ"),
	IDSTR(SBM_ENABLE_ARROWS), _T("���ù��������������Сλ��ֵ,���ػ������"),
	IDSTR(SBM_SETSCROLLINFO), _T("���ù������Ĳ���,����Ϣͨ��SCROLLINFO�ṹָ�����ֲ���,����ָ����Щ�����ɽṹ�е�fMask��Աȷ��"),
	IDSTR(SBM_GETSCROLLINFO), _T("��ȡ�������Ĳ���,���ͱ���Ϣ��,����SCROLLINFO�ṹ�з��ؿؼ��Ķ��ֲ���,��Ȼ�������趨�ṹ��fMask��Ա��ȷ������Ҫȡ����Щ����"),

	//��ť�ؼ���Ϣ
	IDSTR(BM_GETCHECK), _T("��ȡ��ѡ��ť��ѡ���״̬"),
	IDSTR(BM_SETCHECK), _T("���õ�ѡ��ť��ѡ���״̬"),
	IDSTR(BM_GETSTATE), _T("ȷ����ѡ��ť��ѡ���״̬"),
	IDSTR(BM_SETSTATE), _T("�ı䰴ť�ĸ���״̬"),
	IDSTR(BM_SETSTYLE), _T("�ı䰴ť�ķ��"),
	IDSTR(BM_CLICK), _T("ģ���û������ť"),
	IDSTR(BM_GETIMAGE), _T("��ȡ�밴ť�������ͼƬ���(ͼ���λͼ)"),
	IDSTR(BM_SETIMAGE), _T("�Ѱ�ť��ĳ��ͼƬ�����(ͼ���λͼ),ע:��ť����BS_ICON���"),

	//��ť�ؼ�֪ͨ��Ϣ
	IDSTR(BN_CLICKED), _T("�û������˰�ť,����ͨ��WM_COMMAND�����ձ�֪ͨ��Ϣ"),
	IDSTR(BN_DBLCLK), _T("�û�˫���˰�ť(BS_OWNERDRAW��BS_RADIOBUTTON���),����ͨ��WM_COMMAND�����ձ�֪ͨ��Ϣ"),
	IDSTR(BN_DISABLE), _T("��ť����ֹ,����ͨ��WM_COMMAND�����ձ�֪ͨ��Ϣ"),
	IDSTR(BN_DOUBLECLICKED), _T("�û�˫���˰�ť(��BN_DBLCLKͬ)(BS_OWNERDRAW��BS_RADIOBUTTON���),����ͨ��WM_COMMAND�����ձ�֪ͨ��Ϣ"),
	IDSTR(BN_HILITE), _T("�û�ѡ��(������)�˰�ť(��BN_PUSHED��ͬ),����ͨ��WM_COMMAND�����ձ�֪ͨ��Ϣ"),
	IDSTR(BN_KILLFOCUS), _T("��ťʧȥ�˼��̽���(��ť����BS_NOTIFY�����ܷ��ͱ���Ϣ),����ͨ��WM_COMMAND�����ձ�֪ͨ��Ϣ"),
	IDSTR(BN_PAINT), _T("��ťӦ���ػ�,����ͨ��WM_COMMAND�����ձ�֪ͨ��Ϣ"),
	IDSTR(BN_PUSHED), _T("�û������˰�ť(��BN_HILITE��ͬ),����ͨ��WM_COMMAND�����ձ�֪ͨ��Ϣ"),
	IDSTR(BN_SETFOCUS), _T("��ť�յ����̽���(��ť����BS_NOTIFY�����ܷ��ͱ���Ϣ),����ͨ��WM_COMMANDϢ�����ձ�֪ͨ��Ϣ"),
	IDSTR(BN_UNHILITE), _T("��ť�ļ���Ӧ��ȥ��(��BN_UNPUSHED��ͬ),����ͨ��WM_COMMAND�����ձ�֪ͨ��Ϣ"),
	IDSTR(BN_UNPUSHED), _T("��ť�ļ���Ӧ��ȥ��(��BN_UNHILITE��ͬ),����ͨ��WM_COMMAND�����ձ�֪ͨ��Ϣ"),

	IDSTR(WM_KEYFIRST), _T("����WinCEϵͳ,����Ϣ��ʹ��GetMessage��PeekMessage����ʱ,���ڹ��˼�����Ϣ"),
	IDSTR(WM_KEYDOWN), _T("��һ����ϵͳ����������ʱ(<ALT>��û�б�����),�ᷢ�ͱ���Ϣ��ӵ�м��̽���Ĵ���"),
	IDSTR(WM_KEYUP), _T("��һ����ϵͳ�������ͷŵ���ʱ(<ALT>��û�б�����),�ᷢ�ͱ���Ϣ��ӵ�м��̽���Ĵ���"),
	IDSTR(WM_CHAR), _T("����ĳ����,���ѷ���WM_KEYDOWN��WM_KEYUP��Ϣ,����Ϣ���������µİ������ַ���"),
	IDSTR(WM_DEADCHAR), _T("\"���ַ�\"��Ϣ,��ʹ��TranslateMessage��������WM_KEYUP��Ϣʱ,���ͱ���Ϣ��ӵ�м��̽���Ĵ���,ע:���������,��Щ����ֻ�Ǹ��ַ����������,���������ַ�,�ʳ�\"���ַ�\""),
	IDSTR(WM_SYSKEYDOWN), _T("���û���ס<ALT>����ͬʱ�ְ���������ʱ,���ͱ���Ϣ��ӵ�н���Ĵ���"),
	IDSTR(WM_SYSKEYUP), _T("���û��ͷ�һ��������ͬʱ<ALT>��������ʱ,���ͱ���Ϣ��ӵ�н���Ĵ���"),
	IDSTR(WM_SYSCHAR), _T("��WM_SYSKEYDOWN��Ϣ��TranslateMessage���������,���ͱ���Ϣ��ӵ�н���Ĵ���,ע:<ALT>��������"),
	IDSTR(WM_SYSDEADCHAR), _T("\"���ַ�\"��Ϣ,��ʹ��TranslateMessage��������WM_SYSKEYDOWN��Ϣʱ,���ͱ���Ϣ��ӵ�м��̽���Ĵ���,ע:���������,��Щ����ֻ�Ǹ��ַ����������,���������ַ�,�ʳ�\"���ַ�\""),
	IDSTR(WM_KEYLAST), _T("����WinCEϵͳ,����Ϣ��ʹ��GetMessage��PeekMessage����ʱ,���ڹ��˼�����Ϣ"),
	IDSTR(WM_IME_STARTCOMPOSITION), _T("���û���ʼ�������ʱ,ϵͳ�������͸���Ϣ��IME��,IME�򿪱��봰��,ע:���뷨���"),
	IDSTR(WM_IME_ENDCOMPOSITION), _T("���������ʱ,IME���ͱ���Ϣ,�û�����ɽ��ܱ���Ϣ,�Ա��Լ���ʾ�û�����ı���,ע:���뷨���"),
	IDSTR(WM_IME_COMPOSITION), _T("���û��ı��˱���״̬ʱ,���ͱ���Ϣ,Ӧ�ó����ͨ������ImmGetCompositionString������ȡ�µı���״̬"),
	IDSTR(WM_IME_KEYLAST), _T("���û��ı��˱���״̬ʱ,���ͱ���Ϣ,Ӧ�ó����ͨ������ImmGetCompositionString������ȡ�µı���״̬"),
	IDSTR(WM_INITDIALOG), _T("��ĳ�Ի��������ʾǰ���ͱ���Ϣ���öԻ������,ͨ���ñ���Ϣ�Կؼ�����һЩ��ʼ��������ִ����������"),
	IDSTR(WM_COMMAND), _T("�û�ѡ��һ���˵��������ĳ�ؼ�����һ��֪ͨ��Ϣ���丸��,��ĳ��ݼ�������ʱ,����Ϣ������"),
	IDSTR(WM_SYSCOMMAND), _T("���û�ѡ��һ��ϵͳ�˵�����û���󻯻���С����ԭ��ر�ʱ�����ڻ��յ�����Ϣ"),
	IDSTR(WM_TIMER), _T("�����˶�ʱ���¼�"),
	IDSTR(WM_HSCROLL), _T("�����ڵı�׼ˮƽ����������һ�������¼�ʱ,���ͱ���Ϣ���ô���"),
	IDSTR(WM_VSCROLL), _T("�����ڵı�׼��ֱ����������һ�������¼�ʱ,���ͱ���Ϣ���ô���"),
	IDSTR(WM_INITMENU), _T("��һ���˵���������ʱ���ͱ���Ϣ,���������û������ĳ�˵������ĳ�˵�������������������ʾǰ���Ĳ˵�"),
	IDSTR(WM_INITMENUPOPUP), _T("��һ�������˵����Ӳ˵���������ʱ���ͱ���Ϣ,����������������ʾǰ���Ĳ˵�,ȴ������ȫ���˵�"),
	//IDSTR(WM_SYSTIMER), _T("ϵͳ����֪ͨ���������һ����Ϣ"),
	IDSTR(WM_MENUSELECT), _T("���û�ѡ��һ���˵���ʱ,���ͱ���Ϣ���˵���������(һ���Ǵ���)"),
	IDSTR(WM_MENUCHAR), _T("���˵��ѱ��������û�������ĳ�˵��ַ���(�˵��ַ������������š����»���,��ͬ�ڿ�ݼ�),���ͱ���Ϣ���˵���������"),
	IDSTR(WM_ENTERIDLE), _T("��һ��ģ̬�Ի����˵��������״̬ʱ,���ͱ���Ϣ������������,һ��ģ̬�Ի����˵��������״̬�����ڴ�����һ��������ǰ����Ϣ��,û����Ϣ����Ϣ�ж��еȴ�"),
	IDSTR(WM_MENURBUTTONUP), _T("����Ϣ��������Ϊ�˵����ṩһ����֪�����ĵĲ˵�(����ݲ˵�),ҪΪ�˵�����ʾһ�������Ĳ˵�,��ʹ��TPM_RECURSE��ʶ����TrackPopupMenuEx����"),
	IDSTR(WM_MENUDRAG), _T("���û��϶��˵���ʱ,���ͱ���Ϣ���ϷŲ˵���ӵ����,���ò˵�֧����ק,��ʹ��OLE�ϷŴ���Э�������ϷŲ���,ע:�˵�Ҫ����MNS_DRAGDROP���"),
	IDSTR(WM_MENUGETOBJECT), _T("������������뿪�˵���ʱ,����Ϣ���͸�֧���ϷŵĲ˵���ӵ����,��ؽṹ��:MENUGETOBJECTINFO,ע:�˵�Ҫ����MNS_DRAGDROP���"),
	IDSTR(WM_UNINITMENUPOPUP), _T("��һ�������˵����Ӳ˵�������ʱ,���ͱ���Ϣ"),
	IDSTR(WM_MENUCOMMAND), _T("���û���һ���˵�������ѡ��ʱ,�ᷢ�ͱ���Ϣ,�˵�Ҫ����MNS_NOTIFYBYPOS���(��MENUINFO�ṹ��������)"),
	IDSTR(WM_CTLCOLORMSGBOX), _T("ϵͳ������Ϣ��ǰ���ͱ���Ϣ����Ϣ��������ߴ���,ͨ����Ӧ����Ϣ,�����ߴ��ڿ�ͨ��ʹ�ø����������ʾ�豸�ľ����������Ϣ����ı��ͱ���ɫ"),
	IDSTR(WM_CTLCOLOREDIT), _T("��һ���༭��ؼ���Ҫ������ʱ,���ͱ���Ϣ���丸��;ͨ����Ӧ����Ϣ,�����ߴ��ڿ�ͨ��ʹ�ø����������ʾ�豸�ľ�������ñ༭����ı��ͱ���ɫ"),
	IDSTR(WM_CTLCOLORLISTBOX), _T("��һ���б���ؼ���Ҫ������ǰ,���ͱ���Ϣ���丸��;ͨ����Ӧ����Ϣ,�����ߴ��ڿ�ͨ��ʹ�ø����������ʾ�豸�ľ���������б�����ı��ͱ���ɫ"),
	IDSTR(WM_CTLCOLORBTN), _T("Ϣ���ð�ť�ı���ɫ"),
	IDSTR(WM_CTLCOLORDLG), _T("���öԻ���ı���ɫ,ͨ������WinnApp��ʹ��SetDialogBkColor����ʵ��"),
	IDSTR(WM_CTLCOLORSCROLLBAR), _T("���ù������ı���ɫ"),
	IDSTR(WM_CTLCOLORSTATIC), _T("����һ����̬�ؼ��ı���ɫ"),

	//��Ͽ�ؼ���Ϣ
	IDSTR(CB_GETEDITSEL), _T("����ȡ����Ͽ��������༭���ӿؼ��е�ǰ��ѡ�е��ַ�������ֹλ��,��Ӧ����:GetEditSel"),
	IDSTR(CB_LIMITTEXT), _T("����������Ͽ��������༭���ӿؼ������ı��ĳ���"),
	IDSTR(CB_SETEDITSEL), _T("����ѡ����Ͽ��������༭���ӿؼ��еĲ����ַ���,��Ӧ����:GetEditSel"),
	IDSTR(CB_ADDSTRING), _T("��������Ͽ�ؼ�׷��һ���б���(�ַ���)"),
	IDSTR(CB_DELETESTRING), _T("����ɾ����Ͽ���ָ�����б���(�ַ���)"),
	IDSTR(CB_DIR), _T("��������Ͽ�ؼ����������б���ؼ�������һ���ļ����б��嵥"),
	IDSTR(CB_GETCOUNT), _T("���ڷ�����Ͽ�ؼ����б����������"),
	IDSTR(CB_GETCURSEL), _T("���ڷ��ص�ǰ��ѡ���������"),
	IDSTR(CB_GETLBTEXT), _T("��ȡ��Ͽ�ؼ���ָ���б�����ַ���"),
	IDSTR(CB_GETLBTEXTLEN), _T("���ڷ�����Ͽ�ؼ���ָ���б�����ַ����ĳ���(������������0)"),
	IDSTR(CB_INSERTSTRING), _T("����Ͽ�ؼ����������б����ӿؼ��е�ָ��λ�ò����ַ���"),
	IDSTR(CB_RESETCONTENT), _T("���������Ͽ�ؼ������б���"),
	IDSTR(CB_FINDSTRING), _T("����Ͽ�ؼ��и��ݸ������ַ�������ƥ���ַ���(���Դ�Сд)"),
	IDSTR(CB_SELECTSTRING), _T("����Ͽ�ؼ����趨��ָ���ַ�����ƥ����б���Ϊѡ����"),
	IDSTR(CB_SETCURSEL), _T("����Ͽ�ؼ�������ָ�����б���Ϊ��ǰѡ����"),
	IDSTR(CB_SHOWDROPDOWN), _T("������ʾ��ر�����ʽ�������б�ʽ��Ͽ���б���"),
	IDSTR(CB_GETITEMDATA), _T("��Ͽ�ؼ�ÿ���б����һ��32λ�ĸ�������,����Ϣ���ڷ���ָ���б���ĸ�������"),
	IDSTR(CB_SETITEMDATA), _T("���ڸ�����Ͽ����������б�����ָ�����б����32λ��������"),
	IDSTR(CB_GETDROPPEDCONTROLRECT), _T("����ȡ��Ͽ����б������Ļλ��"),
	IDSTR(CB_SETITEMHEIGHT), _T("ָ����Ͽ����б������ʾ�߶�(���ص�)"),
	IDSTR(CB_GETITEMHEIGHT), _T("���ڷ���ָ���б���ĸ߶�(���ص�)"),
	IDSTR(CB_SETEXTENDEDUI), _T("ָ������ʽ�������б�ʽ��Ͽ���ʹ��Ĭ�Ͻ��滹����չ����"),
	IDSTR(CB_GETEXTENDEDUI), _T("���ڷ�����Ͽ��Ƿ������չ����"),
	IDSTR(CB_GETDROPPEDSTATE), _T("����ȡ��Ͽ����б����Ƿ�ɼ�"),
	IDSTR(CB_FINDSTRINGEXACT), _T("����Ͽ��в����ַ���,���Դ�Сд,��CB_FINDSTRING��ͬ,����Ϣ���������ַ�����ͬ"),
	IDSTR(CB_SETLOCALE), _T("������Ͽ��б��ǰ������������Դ���"),
	IDSTR(CB_GETLOCALE), _T("��ȡ��Ͽ��б��ǰ������������Դ���"),
	IDSTR(CB_GETTOPINDEX), _T("��ȡ��Ͽ����б����е�һ���ɼ��������"),
	IDSTR(CB_SETTOPINDEX), _T("���ڽ�ָ������Ͽ����б�������Ϊ�б���ĵ�һ���ɼ���"),
	IDSTR(CB_GETHORIZONTALEXTENT), _T("���ڷ�����Ͽ�ˮƽ�������ܿ���(���ص�)(Ҫ����ˮƽ������)"),
	IDSTR(CB_SETHORIZONTALEXTENT), _T("�����趨��Ͽ��е��б���Ŀ���"),
	IDSTR(CB_GETDROPPEDWIDTH), _T("ȡ��Ͽ����б���Ŀ���(���ص�)"),
	IDSTR(CB_SETDROPPEDWIDTH), _T("�����趨��Ͽ��е��б���������������"),
	IDSTR(CB_INITSTORAGE), _T("ֻ������Win95,����Ҫ����Ͽ����б����м����������ʱ,����Ϣ��Ԥ�ȷ���һ���ڴ�,����������ӱ����η����ڴ�,�Ӷ��ӿ���������ٶ�"),
	IDSTR(CB_MSGMAX), _T("����Ϣ������������Ϣֵ:0x0162,0x0163,0x0165,��Ϣ���岻��,����������Visual Studio 6��Ŀ¼Ҳֻ���䶨��,ȴδ����ʹ�õ���ش���"),

	//��Ͽ�ؼ�֪ͨ��Ϣ
	IDSTR(CBN_CLOSEUP), _T("֪ͨ����(ͨ��WM_COMMAND��֪),��Ͽ���б��򱻹ر�"),
	IDSTR(CBN_DBLCLK), _T("֪ͨ����(ͨ��WM_COMMAND��֪),�û�˫������Ͽ��е�һ���ַ���"),
	IDSTR(CBN_DROPDOWN), _T("֪ͨ����(ͨ��WM_COMMAND��֪),��Ͽ���б��򱻵���"),
	IDSTR(CBN_EDITCHANGE), _T("֪ͨ����(ͨ��WM_COMMAND��֪),�û��޸�����Ͽ������༭���е��ı�"),
	IDSTR(CBN_EDITUPDATE), _T("֪ͨ����(ͨ��WM_COMMAND��֪),��Ͽ������༭���ڵ��ı���������"),
	IDSTR(CBN_ERRSPACE), _T("֪ͨ����(ͨ��WM_COMMAND��֪),��Ͽ��ڴ治��"),
	IDSTR(CBN_KILLFOCUS), _T("֪ͨ����(ͨ��WM_COMMAND��֪),��Ͽ�ʧȥ���뽹��"),
	IDSTR(CBN_SELCHANGE), _T("֪ͨ����(ͨ��WM_COMMAND��֪),ѡ������Ͽ��е�һ��"),
	IDSTR(CBN_SELENDCANCEL), _T("֪ͨ����(ͨ��WM_COMMAND��֪),�û�����Ͽ��ѡ��Ӧ����ȡ��"),
	IDSTR(CBN_SELENDOK), _T("֪ͨ����(ͨ��WM_COMMAND��֪),�û�����Ͽ��ѡ���ǺϷ���"),
	IDSTR(CBN_SETFOCUS), _T("֪ͨ����(ͨ��WM_COMMAND��֪),��Ͽ������뽹��"),

	//�б���ؼ���Ϣ
	IDSTR(LB_ADDSTRING), _T("���б����������ַ���"),
	IDSTR(LB_INSERTSTRING), _T("���б����в���һ����Ŀ���ݻ��ַ���������LB_ADDSTRING��Ϣ,����Ϣ���ἤ��LBS_SORT��ʽ������Ŀ��������"),
	IDSTR(LB_DELETESTRING), _T("ɾ���б����е�һ���ַ���"),
	IDSTR(LB_SELITEMRANGEEX), _T("�ڶ�ѡ״̬�µ��б�����ѡ��һ��������������Ŀ"),
	IDSTR(LB_RESETCONTENT), _T("����б����������б���"),
	IDSTR(LB_SETSEL), _T("�ڶ�ѡ״̬�µ��б�����ѡ��һ���ַ���"),
	IDSTR(LB_SETCURSEL), _T("���б�����ѡ��һ���ַ���,���������ڵ���Ŀ��������Ұ��,��������ѡ�е��ַ���"),
	IDSTR(LB_GETSEL), _T("����б�����һ����Ŀ��ѡ��״̬"),
	IDSTR(LB_GETCURSEL), _T("����б����е�ǰ��ѡ��Ŀ�����������ڵ�ѡ״̬���б�����Ч"),
	IDSTR(LB_GETTEXT), _T("���б����л��һ���ַ���"),
	IDSTR(LB_GETTEXTLEN), _T("���һ���б������ַ����ĳ���"),
	IDSTR(LB_GETCOUNT), _T("����б�������Ŀ������"),
	IDSTR(LB_SELECTSTRING), _T("�������ڵ�ѡ���б���,�趨��ָ���ַ�����ƥ����б���Ϊѡ����,������б�����ʹѡ����ɼ�"),
	IDSTR(LB_DIR), _T("���б������г��ļ���"),
	IDSTR(LB_GETTOPINDEX), _T("�����б����е�һ���ɼ��������"),
	IDSTR(LB_FINDSTRING), _T("���б����в���ƥ���ַ���(���Դ�Сд)"),
	IDSTR(LB_GETSELCOUNT), _T("�����ڶ���ѡ���б���,����Ϣ���ڷ���ѡ�������Ŀ"),
	IDSTR(LB_GETSELITEMS), _T("�����ڶ���ѡ���б���,����Ϣ���ڻ��ѡ�������Ŀ��λ��"),
	IDSTR(LB_SETTABSTOPS), _T("�����б���Ĺ��(���뽹��)վ��������˳���"),
	IDSTR(LB_GETHORIZONTALEXTENT), _T("�����б���Ŀɹ����Ŀ���(���ص�)"),
	IDSTR(LB_SETHORIZONTALEXTENT), _T("����Ϣ�����б���Ĺ�������"),
	IDSTR(LB_SETCOLUMNWIDTH), _T("Ϊ�б���ָ������"),
	IDSTR(LB_ADDFILE), _T("Ϊ�б��������ļ���"),
	IDSTR(LB_SETTOPINDEX), _T("�����б�����ָ�����б�������Ϊ�б���ĵ�һ���ɼ���,�Ὣ�б�����������ʵ�λ��"),
	IDSTR(LB_GETITEMRECT), _T("�����б����л���б���Ŀͻ�����RECT"),
	IDSTR(LB_GETITEMDATA), _T("�б�����ÿ���б���и�32λ��������,����Ϣ���ڷ���ָ���б���ĸ�������"),
	IDSTR(LB_SETITEMDATA), _T("���ڸ����б�����ָ���б����32λ��������"),
	IDSTR(LB_SELITEMRANGE), _T("�����ڶ���ѡ���б���,����ʹָ����Χ�ڵ��б���ѡ�л���ѡ"),
	IDSTR(LB_SETANCHORINDEX), _T("�����б���������������ѡ�еı����ָ������"),
	IDSTR(LB_GETANCHORINDEX), _T("�����б�����������ѡ�е��������"),
	IDSTR(LB_SETCARETINDEX), _T("�����б��������ü������뽹�㵽ָ������"),
	IDSTR(LB_GETCARETINDEX), _T("�����б����з��ؾ��о��ν������Ŀ����"),
	IDSTR(LB_SETITEMHEIGHT), _T("�����б�����ָ���б�����ʾ�߶�"),
	IDSTR(LB_GETITEMHEIGHT), _T("�����б����з����б�����ĳһ��ĸ߶�(���ص�)"),
	IDSTR(LB_FINDSTRINGEXACT), _T("�����б����в����ַ���(���Դ�Сд),��LB_FINDSTRING��ͬ,����Ϣ���������ַ�����ͬ"),
	IDSTR(LB_SETLOCALE), _T("�����б����������б��ǰ������������Դ���,���û�ʹ��LB_ADDSTRING����Ͽ��е��б��������Ӽ�¼,��ʹ��LBS_SORT��������������ʱ,����ʹ�ø����Դ���"),
	IDSTR(LB_GETLOCALE), _T("�����б����л�ȡ�б��ǰ������������Դ���,���û�ʹ��LB_ADDSTRING����Ͽ��е��б��������Ӽ�¼,��ʹ��LBS_SORT��������������ʱ,����ʹ�ø����Դ���"),
	IDSTR(LB_SETCOUNT), _T("�����б��������ñ�����Ŀ"),
	IDSTR(LB_INITSTORAGE), _T("ֻ������Win95�汾,����Ҫ���б����м����������ʱ,����Ϣ��Ԥ�ȷ���һ���ڴ�,�������Ժ�Ĳ�����һ�δη����ڴ�"),
	IDSTR(LB_ITEMFROMPOINT), _T("�����б����л����ָ�����������Ŀ����"),
	IDSTR(LB_MSGMAX), _T("����Ϣ������������Ϣֵ:0x01B0,0x01B1,0x01B3,,��Ϣ���岻��,����������Visual Studio 6��Ŀ¼Ҳֻ���䶨��,ȴδ����ʹ�õ���ش���"),

	//�б���ؼ�֪ͨ��Ϣ
	IDSTR(LBN_DBLCLK), _T("֪ͨ����(ͨ��WM_COMMAND��֪),�û�˫�����б����е�һ��"),
	IDSTR(LBN_ERRSPACE), _T("֪ͨ����(ͨ��WM_COMMAND��֪),�б����ڴ治��"),
	IDSTR(LBN_KILLFOCUS), _T("֪ͨ����(ͨ��WM_COMMAND��֪),�б�������ʧȥ���뽹��"),
	IDSTR(LBN_SELCANCEL), _T("֪ͨ����(ͨ��WM_COMMAND��֪),ѡ��ȡ��"),
	IDSTR(LBN_SELCHANGE), _T("֪ͨ����(ͨ��WM_COMMAND��֪),ѡ�����б����е���һ��"),
	IDSTR(LBN_SETFOCUS), _T("֪ͨ����(ͨ��WM_COMMAND��֪),�б��������뽹��"),

	IDSTR(WM_MOUSEFIRST), _T("����ƶ�ʱ����(��WM_MOUSEMOVE��ֵ),�������ж������Ϣ�ķ�Χ,����:if(message >= WM_MOUSEFIRST)&&(message <= WM_MOUSELAST)"),
	IDSTR(WM_MOUSEMOVE), _T("�ƶ����"),
	IDSTR(WM_LBUTTONDOWN), _T("����������"),
	IDSTR(WM_LBUTTONUP), _T("�ͷ�������"),
	IDSTR(WM_LBUTTONDBLCLK), _T("˫��������"),
	IDSTR(WM_RBUTTONDOWN), _T("��������Ҽ�"),
	IDSTR(WM_RBUTTONUP), _T("�ͷ�����Ҽ�"),
	IDSTR(WM_RBUTTONDBLCLK), _T("˫������Ҽ�"),
	IDSTR(WM_MBUTTONDOWN), _T("��������м�"),
	IDSTR(WM_MBUTTONUP), _T("�ͷ�����м�"),
	IDSTR(WM_MBUTTONDBLCLK), _T("˫������м�"),
	IDSTR(WM_MOUSEWHEEL), _T("���������ת��ʱ,���ͱ���Ϣ����ǰӵ�н���Ŀؼ�"),
	IDSTR(WM_MOUSELAST), _T("WM_MBUTTONDBLCLK�ı���,ͨ�������ж������Ϣ�ķ�Χ,��Ӧ�Ļ���WM_MOUSEFIRST,����:if(message > =  WM_MOUSEFIRST)&&(message <= WM_MOUSELAST)"),
	IDSTR(WM_PARENTNOTIFY), _T("��MDI�Ӵ��ڱ�����������,���û�����һ��������������Ӵ�����ʱ,���ͱ���Ϣ���丸��"),
	IDSTR(WM_ENTERMENULOOP), _T("���ͱ���Ϣ֪ͨӦ�ó�����������ѽ���˵�ѭ��ģʽ"),
	IDSTR(WM_EXITMENULOOP), _T("���ͱ���Ϣ֪ͨӦ�ó�������������˳��˵�ѭ��ģʽ"),
	IDSTR(WM_NEXTMENU), _T("��ʹ�����ͷ�������Ҽ�ͷ�����ڲ˵�����ϵͳ�˵�֮���л�ʱ,�ᷢ�ͱ���Ϣ��Ӧ�ó���,��ؽṹ��:MDINEXTMENU"),
	IDSTR(WM_SIZING), _T("���û����ڵ������ڴ�Сʱ,���ͱ���Ϣ������;ͨ������ϢӦ�ó���ɼ��Ӵ��ڴ�С��λ��,Ҳ���޸�����"),
	IDSTR(WM_CAPTURECHANGED), _T("����ʧȥ��������ʱ,���ͱ���Ϣ������"),
	IDSTR(WM_MOVING), _T("���û����ƶ�����ʱ���ͱ���Ϣ,ͨ������ϢӦ�ó����Լ��Ӵ��ڴ�С��λ��,Ҳ���޸�����"),
	IDSTR(WM_POWERBROADCAST), _T("����Ϣ���͸�Ӧ�ó�����֪ͨ���йص�Դ�����¼�,�����������ʱ�ᷢ�ͱ���Ϣ"),
	IDSTR(WM_DEVICECHANGE), _T("���豸��Ӳ�����øı�ʱ,���ͱ���Ϣ��Ӧ�ó�����豸��������"),
	IDSTR(WM_MDICREATE), _T("���ͱ���Ϣ�����ĵ�Ӧ�ó���Ŀͻ�����������һ��MDI�Ӵ���"),
	IDSTR(WM_MDIDESTROY), _T("���ͱ���Ϣ�����ĵ�Ӧ�ó���Ŀͻ��������ر�һ��MDI�Ӵ���"),
	IDSTR(WM_MDIACTIVATE), _T("���ͱ���Ϣ�����ĵ�Ӧ�ó���Ŀͻ�����֪ͨ�ͻ����ڼ�����һ��MDI�Ӵ���,���ͻ������յ�����Ϣ��,������WM_MDIACTIVE��Ϣ��MDI�Ӵ���(δ����)��������"),
	IDSTR(WM_MDIRESTORE), _T("���ͱ���Ϣ��MDI�ͻ�����,���Ӵ��ڴ������С���ָ���ԭ���Ĵ�С"),
	IDSTR(WM_MDINEXT), _T("���ͱ���Ϣ��MDI�ͻ�����,������һ����ǰһ������"),
	IDSTR(WM_MDIMAXIMIZE), _T("���ͱ���Ϣ��MDI�ͻ����������һ��MDI�Ӵ���"),
	IDSTR(WM_MDITILE), _T("���ͱ���Ϣ��MDI�ͻ�����,��ƽ�̷�ʽ������������MDI�Ӵ���"),
	IDSTR(WM_MDICASCADE), _T("���ͱ���Ϣ��MDI�ͻ�����,�Բ����ʽ������������MDI�Ӵ���"),
	IDSTR(WM_MDIICONARRANGE), _T("���ͱ���Ϣ��MDI�ͻ�������������������С����MDI�Ӵ���"),
	IDSTR(WM_MDIGETACTIVE), _T("���ͱ���Ϣ��MDI�ͻ��������ҵ�������Ӵ��ھ��"),
	IDSTR(WM_MDISETMENU), _T("���ͱ���Ϣ��MDI�ͻ�����,��MDI�˵������Ӵ��ڵĲ˵�"),
	IDSTR(WM_ENTERSIZEMOVE), _T("��ĳ���ڽ����ƶ��������С��ģʽѭ��ʱ,����Ϣ���͵��ô���"),
	IDSTR(WM_EXITSIZEMOVE), _T("ȷ���û��ı䴰�ڴ�С��ı䴰��λ�õ��¼��Ǻ�ʱ��ɵ�"),
	IDSTR(WM_DROPFILES), _T("����Ϸ�ʱ,�����¼�����ʱ���ͱ���Ϣ,����:�ļ��ϷŹ���"),
	IDSTR(WM_MDIREFRESHMENU), _T("���ͱ���Ϣ�����ĵ�Ӧ�ó���Ŀͻ�����,���ݵ�ǰMDI�Ӵ��ڸ���MDI��ܴ��ڵĲ˵�"),
	//0x0235
	//......
	//0x0280
	IDSTR(WM_IME_SETCONTEXT), _T("Ӧ�ó���Ĵ��ڼ���ʱ,ϵͳ����Ӧ�ó�����WM_IME_SETCONTEXT��Ϣ,ע:���뷨���"),
	IDSTR(WM_IME_NOTIFY), _T("��ʹ��WM_IME_NOTIFY��Ϣ��֪ͨ����IME����״̬�ĳ���ı�,ע:���뷨���"),
	IDSTR(WM_IME_CONTROL), _T("��ʹ��WM_IME_CONTROL��Ϣ���ı���ĸ��ϴ��ڵ�λ��,ע:���뷨���"),
	IDSTR(WM_IME_COMPOSITIONFULL), _T("�û��ӿڴ��ڲ������ӱ��봰�ڵĳߴ�ʱ,IME�û��ӿڴ��ڽ�����WM_IME_COMPOSITIONFULL��Ϣ,�ɲ�����,ע:���뷨���"),
	IDSTR(WM_IME_SELECT), _T("ϵͳ����WM_IME_SELECT�Ա�ѡ��һ���µ�IME���뷨,ע:���뷨���"),
	IDSTR(WM_IME_CHAR), _T("�������뷨��������ʱ,�ᷢ��WM_IME_CHAR��Ϣ"),
	IDSTR(WM_IME_REQUEST), _T("Ӧ�ó����������뷨ʱ,�������ͱ���Ϣ"),
	IDSTR(WM_IME_KEYDOWN), _T("�����뷨¼�ִ����а��°���ʱ,�������ͱ���Ϣ"),
	IDSTR(WM_IME_KEYUP), _T("�����뷨¼�ִ������ͷŰ���ʱ,�������ͱ���Ϣ"),
	IDSTR(WM_MOUSEHOVER), _T("����ƹ��ؼ�ʱ,�������ͱ���Ϣ"),
	IDSTR(WM_MOUSELEAVE), _T("����뿪�ؼ�ʱ,�������ͱ���Ϣ"),
	IDSTR(WM_CUT), _T("Ӧ�ó����ͱ���Ϣ��һ���༭�����Ͽ���ɾ����ǰѡ����ı�"),
	IDSTR(WM_COPY), _T("Ӧ�ó����ͱ���Ϣ��һ���༭�����Ͽ�,�Ա���CF_TEXT��ʽ���Ƶ�ǰѡ����ı���������"),
	IDSTR(WM_PASTE), _T("Ӧ�ó����ͱ���Ϣ���༭�����Ͽ�,�Ա�Ӽ������еõ�����"),
	IDSTR(WM_CLEAR), _T("Ӧ�ó����ͱ���Ϣ���༭�����Ͽ�,�������ǰѡ�������"),
	IDSTR(WM_UNDO), _T("Ӧ�ó����ͱ���Ϣ���༭�����Ͽ�,�Գ������һ�β���"),
	IDSTR(WM_RENDERFORMAT), _T("Ӧ�ó�����Ҫϵͳ���а�����ʱ,�������ͱ���Ϣ"),
	IDSTR(WM_RENDERALLFORMATS), _T("Ӧ�ó����˳�ʱ�ڳ����˳�ʱ,ϵͳ�����ǰ�����͸���Ϣ,Ҫ���ṩ���и�ʽ�ļ���������,����������ݶ�ʧ"),
	IDSTR(WM_DESTROYCLIPBOARD), _T("������EmptyClipboard����ʱ,���ͱ���Ϣ���������������"),
	IDSTR(WM_DRAWCLIPBOARD), _T("������������ݱ仯ʱ,���ͱ���Ϣ��������۲������׸�����;�������ü�����۲촰������ʾ�������������"),
	IDSTR(WM_PAINTCLIPBOARD), _T("�����������CF_OWNERDIPLAY��ʽ������,���Ҽ�����۲촰�ڵĿͻ�����Ҫ�ػ�ʱ,�������ͱ���Ϣ"),
	IDSTR(WM_VSCROLLCLIPBOARD), _T("��������鿴���Ĵ�ֱ������������ʱ,�������ͱ���Ϣ"),
	IDSTR(WM_SIZECLIPBOARD), _T("�����������CF_OWNERDIPLAY��ʽ������,���Ҽ�����۲촰�ڵĿͻ�����Ĵ�С�Ѹı�ʱ,����Ϣͨ��������۲촰�ڷ��͸��������������"),
	IDSTR(WM_ASKCBFORMATNAME), _T("ͨ��������۲촰�ڷ��ͱ���Ϣ���������������,������һ��CF_OWNERDISPLAY��ʽ�ļ����������"),
	IDSTR(WM_CHANGECBCHAIN), _T("��һ�����ڴӼ�����۲�������ȥʱ,���ͱ���Ϣ��������۲������׸�����"),
	IDSTR(WM_HSCROLLCLIPBOARD), _T("����Ϣͨ��һ��������۲촰�ڷ��͸��������������,�������ڵ����������CFOWNERDISPALY��ʽ������,�����и��¼��ڼ�����۲촰��ˮƽ��������,������Ӧ����������ͼ�񲢸��¹�������ֵ"),
	IDSTR(WM_QUERYNEWPALETTE), _T("����Ϣ���͸���Ҫ�յ�����Ĵ���,����Ϣ��ʹ�������յ�����ʱͬʱ�л���ʵ���߼���ɫ��"),
	IDSTR(WM_PALETTEISCHANGING), _T("��һ��Ӧ�ó�����Ҫʵ�������߼���ɫ��ʱ,������Ϣ֪ͨ���е�Ӧ�ó���"),
	IDSTR(WM_PALETTECHANGED), _T("����Ϣ��һ��ӵ�н���Ĵ���ʵ�������߼���ɫ���,���ͱ���Ϣ�����ж������ص��Ĵ���,�Դ����ı�ϵͳ��ɫ��"),
	IDSTR(WM_HOTKEY), _T("���û�������RegisterHotKey����ע����ȼ�ʱ,���ͱ���Ϣ"),
	IDSTR(WM_PRINT), _T("���ͱ���Ϣ��һ������������ָ�����豸�������л�������,�����ڴ��ڽ�ͼ,�����ӿؼ���ͼʱ�õ��������ӿؼ��ȴ�ĺڿ�"),
	IDSTR(WM_PRINTCLIENT), _T("�ͱ���Ϣ��һ������������ָ�����豸�������л�����ͻ���(��ͨ������һ����ӡ���豸��������)"),
	IDSTR(WM_HANDHELDFIRST), _T("��Ϣ����δ֪,����������Visual Studio 6��Ŀ¼Ҳֻ���䶨��,ȴδ����ʹ�õ���ش���"),
	IDSTR(WM_HANDHELDLAST), _T("��Ϣ����δ֪,����������Visual Studio 6��Ŀ¼Ҳֻ���䶨��,ȴδ����ʹ�õ���ش���"),
	IDSTR(WM_AFXFIRST), _T("ָ���׸�AFX��Ϣ(MFC)"),
//	IDSTR(WM_QUERYAFXWNDPROC), _T("����Ϣ��MFC�ڲ�����ȷ�ϴ��ڹ����Ƿ�ʹ��AfxWndProc"),
//	IDSTR(WM_SIZEPARENT), _T("MFC�Զ������Ϣ,MFC�������ڿ�ܲ�����ͨ�����Ӵ��ڷ�����ӦWM_SIZEPARENT����ɵ�,��ܴ��ڷ��ͱ���Ϣ�õ���SendMessage,���������Ӵ�����OnSizeParent��ӦWM_SIZEPARENT��Ϣ"),
//	IDSTR(WM_IDLEUPDATECMDUI), _T("MFC�Լ������ʹ�õ���Ϣ,��Ӧ�ó��������д���״̬ʱ,�����ͱ���Ϣ,�������й������û������״̬��������������,�Ӷ��ı���״̬,��Ӧ����Ϣ��Ӧ����Ϊ:OnIdleUpdateCmdUI"),
//	IDSTR(WM_INITIALUPDATE), _T("MFC��������Ϣ,���ڴ����˵�����ݼ�,����WM_INITIALUPDATE��Ϣ�������Ӵ���,��Ϣ��Ӧ����Ϊ:CView::OnInitialUpdate"),
//	IDSTR(WM_COMMANDHELP), _T("����Ϣ����ʵ��MFC�����������а���,����<F1��>����Ϣ��ӳ�䵽CWinApp::OnHelp���ú�������������ܴ��ڷ��ͱ���Ϣ,����Ϣ��Ӧ�������Զ����µ�,��Ӧ����Ϣ��Ӧ����Ϊ:ON_WM_HELPINFO"),
//	IDSTR(WM_HELPHITTEST), _T("����Ϣ����ʵ��MFC�����������а���,����Ϣ�����ֹ�����"),
//	IDSTR(WM_EXITHELPMODE), _T("����Ϣ����ʵ��MFC�����������а���,����Ϣ�����ֹ�����"),
//	IDSTR(WM_RECALCPARENT), _T("MFC�Լ������ʹ�õ���Ϣ,��Ӧ����Ϣ��Ӧ����Ϊ:CMainFrame::OnReCalcParent,����Ϣ��CView���͸�CMainFrame��ܴ����Ա����²��ô���"),
//	IDSTR(WM_SIZECHILD), _T("MFC�Լ������ʹ�õ���Ϣ,���û����µ���COleResizeBar�Ĵ�Сʱ,��COleResizeBar���͸��������ߴ���),"),
//	IDSTR(WM_KICKIDLE), _T("����Ϣ��MFC�жԿ��н��д�����һ��δ��������Ϣ,��Ϣ�ò�������WM_KICKIDLE��Ϣ,�յ�����Ϣ��,ֱ�ӷ���,WM_KICKIDLE�������̼����д�����ִ��,����Ϊһ������Ϣ��ʹ::GetMessage()����"),
//	IDSTR(WM_QUERYCENTERWND), _T("MFC�ڲ�������δ������Ϣ,lParam:HWND to use as centering parent;"),
//	IDSTR(WM_DISABLEMODAL), _T("MFC�ڲ�������δ������Ϣ,lResult = 0,disable during modal state;lResult = 1,don't disable"),
//	IDSTR(WM_FLOATSTATUS), _T("MFC�ڲ�������δ������Ϣ,wParam combination of FS_* flags below"),
//	IDSTR(WM_ACTIVATETOPLEVEL), _T("MFC�ڲ�������δ������Ϣ,wParam = nState(like WM_ACTIVATE);lParam = pointer to HWND[2];lParam[0] = hWnd getting WM_ACTIVATE;lParam[1] = hWndOther"),
//	IDSTR(WM_QUERY3DCONTROLS), _T("MFC�ڲ�������δ������Ϣ,lResult != 0 if 3D controls wanted"),
//	IDSTR(WM_RESERVED_0370), _T("MFC�ڲ�������δ������MFC����Ҳδʹ�õ���Ϣ"),
//	IDSTR(WM_RESERVED_0371), _T("MFC�ڲ�������δ������MFC�Լ�Ҳδʹ�õ���Ϣ"),
//	IDSTR(WM_RESERVED_0372), _T("MFC�ڲ�������δ������MFC�Լ�Ҳδʹ�õ���Ϣ"),
//	IDSTR(WM_SOCKET_NOTIFY), _T("����MSDN�й�����MFC�ڲ���Ϣ,����Ϣ����socket����socket�¼��Ѿ�����(socket����:CSocketWnd,����,���ձ���Ϣ,��Ӧ:OnSocketNotify)),"),
//	IDSTR(WM_SOCKET_DEAD), _T("MFC�ڲ���Ϣ,MFCά�����׽��ֵ�ӳ��,���׽����Ǹ��ѹرյ��׽���,�μ�sockcore.cpp"),
//	IDSTR(WM_SETMESSAGESTRING), _T("MFC�ڲ���Ϣ,���͸���ܴ���Ҫ�������״̬���ַ�����Ϣ,΢��MFC TN024�ĵ����и���Ϣ������,��Ӧ����:OnSetMessageString"),
//	IDSTR(WM_POPMESSAGESTRING), _T("MFC�ڲ���Ϣ,������������״̬��,��Ӧ���ַ�����\")Ready\_T(",��Ӧ����:OnPopMessageString"),
//	IDSTR(WM_HELPPROMPTADDR), _T("MFC�ڲ���Ϣ,������������Ŀ�ܴ����м���m_dwPromptContext��ַ,ע:<F1>�����İ������"),
//	IDSTR(WM_OCC_LOADFROMSTREAM), _T("MFC�ڲ���Ϣ,OCC��OLE control containers,�μ����LoadFromStream����"),
//	IDSTR(WM_OCC_LOADFROMSTORAGE), _T("MFC�ڲ���Ϣ,OCC��OLE control container,�μ����LoadFromStorage����"),
//	IDSTR(WM_OCC_INITNEW), _T("MFC�ڲ���Ϣ,OCC��OLE control container,�μ����InitNew����"),
//	IDSTR(WM_OCC_LOADFROMSTREAM_EX), _T("MFC�ڲ���Ϣ,OCC��OLE control container,�μ����LoadFromStreamEx����"),
//	IDSTR(WM_OCC_LOADFROMSTORAGE_EX), _T("MFC�ڲ���Ϣ,OCC��OLE control container,�μ�:ATLHOST.H/OCCMGR.CPP/WINCORE.CPP����ش���"),
//	IDSTR(WM_QUEUE_SENTINEL), _T("MFC�ڲ���Ϣ,����������Ϣ����,\")QUEUE SENTINEL\_T("��Ϊ��Ϣ�ڱ�"),
//	IDSTR(WM_RESERVED_037C), _T("MFC�ڲ�����,������ʹ��"),
//	IDSTR(WM_RESERVED_037D), _T("MFC�ڲ�����,������ʹ��"),
//	IDSTR(WM_RESERVED_037E), _T("MFC�ڲ�����,������ʹ��"),
//	IDSTR(WM_FORWARDMSG), _T("ATL�ж���,��һ�����ڽ��յ���Ϣ���ݸ���һ�����ڽ��д���"),
	IDSTR(WM_AFXLAST), _T("ָ��ĩ��afx��Ϣ"),
	IDSTR(WM_PENWINFIRST), _T("ָ���׸�Pen Window��Ϣ,�μ�:PENWIN.H/WINUSER.H"),
	IDSTR(WM_PENWINLAST), _T("ָ��ĩ��Pen Window��Ϣ,�μ�:PENWIN.H/WINUSER.H"),


	IDSTR(WM_APP), _T("���ڰ���Ӧ�ó����Զ���˽����Ϣ,ͨ����ʽΪ:WM_APP + X"),
	IDSTR(WM_USER), _T("���ڰ���Ӧ�ó����Զ���˽����Ϣ,ͨ����ʽΪ:WM_USER + X"),
	

	
	{ 0, NULL, NULL }
};