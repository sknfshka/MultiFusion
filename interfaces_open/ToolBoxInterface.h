#ifndef __TOOLBOX_INTERFACE_H__
#define __TOOLBOX_INTERFACE_H__

#include <QPen>
#include <QBrush>
#include <QWidget>
#include <QGridLayout>

#include "Plugin.h"
#include "FigureToolInterface.h"

/**
*	@file toolboxinterface.h � ������ ����� ������ ���������, ������� ������ �������������
*		����� ������, ���������� �� ���������� ������ ������������.
*/


/**
*		���������, ������� ������ �������������
*	����� ������, ���������� �� ���������� ������ ������������.
*	������, ����������� ������ ��������� ������ ������������� �� ������ ������� ������
*	QWidget ��� �� ���� ������.
*
*		����� ���������� ������� ����������, ����� ����� ������ ������ �������������
*	��������� �������:
*
*	@code
*
*	void selectionToolSelected(); 		//������ ���������� ��������� ��������.
*	void addPointToolSelected();		//������ ���������� ���������� ����� � ������.
*	void zoomInToolSelected();			//������ ������ ���������� �������� �����.
*	void zoomOutToolSelected();			//������ ������ ���������� �������� �����.
*	void closedChanged( bool closed );	//������ ������ "�����������" ������.
*							//� ��������� ������ ����������� �������� �����������
*							//(�.�. true, ���� ������ ������ ���� �������� � false
*							//� ��������� ������).
*
*	void toolSelected( FigureToolInterface *tool ); //������ ��������� ���������, �����������
*									//��� ������. � ��������� ������ ������������ ��� �����
*									//��������� ������������� � ����������� ������ �������� ������.
*
*	void penChanged( const QPen &p );	//���������� � ��� ������, ����� ������������ ������� ��������� ��� ��� �����.
*	void brushChanged( const QBrush &b ); //���������� � ��� ������, ����� ������������ ������� ��������� ��� ��� �������.
*
*	@endcode
*/
class ToolBoxInterface: public QWidget
{
	signals:
		 /**
		 * ������������ ����� ���������� �������, ������� ��� ����� ��������� � �������
		 * @param event ��� �������
		 */
		void StateChanged(QString event);
	public:
		virtual QGridLayout* getFigureLayout() = 0;

		virtual QVBoxLayout& getMainLayout() = 0;

		/**
		*	����� ������ ���������� ������� ��������� ��������� �� ������ ����������� ������.
		*
		*	@return true, ���� ������ ������ ���� ��������.
		*/
		virtual bool isClosedChecked() const = 0;

		/**
		*	����� ������ ������������� ������� ��������� ��������� �� ������ ����������� ������.
		*
		*	@param closed ����� ���������� � true, ���� ������ ������ ���� ��������.
		*/
		virtual void setClosedChecked( bool closed ) = 0;

		/**
		*	�����������.
		*/
		ToolBoxInterface(){};

		/**
		*	����������.
		*/
		virtual ~ToolBoxInterface(){};
};

Q_DECLARE_INTERFACE( ToolBoxInterface, "com.Tailer.MultiFusion.ToolBoxInterface/1.0" )

/**
*	�������� ��������� �� ����� ������ � ���������� �� ��������� ToolboxInterface.
*
*	@return ���������� ��������� ��� 0, ���� ��������� ������.
*/
template < class T > inline ToolBoxInterface* TOOLBOX( T *o )
{
	return qobject_cast< ToolBoxInterface* >( o );
}

#endif /* __TOOLBOX_INTERFACE_H__ */
