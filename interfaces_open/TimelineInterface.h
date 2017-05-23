#ifndef __TIMELINE_INTERFACE_H__
#define __TIMELINE_INTERFACE_H__

/**
*	@file timelineinterface.h � ������ ����� ������ ���������, ������� ������ �������������
*		����� ������, ���������� �� �.�. ��������.
*/

/**
*		���������, ������� ������ ������������� ����� ������, ���������� �� �.�. ��������.
*	������, ����������� ������ ��������� ������ ������������� �� ������ ������� ������
*	QWidget ��� �� ���� ������.
*
*		����� ���������� ������� ����������, ����� ����� ������ ������ �������������
*	��������� �������:
*
*	@code
*
*	void playPressed(); 	//������ ��������������, ����� ������������ ����� �� ������ "Play".
*	void stopPressed();		//������ ��������������, ����� ������������ ����� �� ������ "Stop".
*	void pausePressed();	//������ ��������������, ����� ������������ ����� �� ������ "Pause".
*	void frameChanged( int frame );//������ ��������������, ����� ������������ ������ ������� ����.
*
*	@endcode
*/
class TimelineInterface
{
	public:
		/**
		*	�����������.
		*/
		TimelineInterface()
				{

				}
		virtual int getFps() = 0;
		/**
		*	����������.
		*/
		virtual ~TimelineInterface()
		{
		}
};

Q_DECLARE_INTERFACE( TimelineInterface, "com.alxn1.MultiFusion.TimelineInterface/1.0" )

/**
*	�������� ��������� �� ����� ������ � ���������� �� ��������� TimelineInterface.
*
*	@return ���������� ��������� ��� 0, ���� ��������� ������.
*/
template < class T > inline TimelineInterface* TIMELINE( T *o )
{
	return qobject_cast< TimelineInterface* >( o );
}

#endif /* __TIMELINE_INTERFACE_H__ */
