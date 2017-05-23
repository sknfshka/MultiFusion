#ifndef __PEN_EDITOR_INTERFACE_H__
#define __PEN_EDITOR_INTERFACE_H__

#include <QPainter>

/**
*	@file peneditorinterface.h � ������ ����� ������ ���������, ������� ������ �������������
*		����� ������, ���������� �� �������������� ���� � �������� �����.
*/

/**
*		���������, ������� ������ �������������
*	����� ������, ���������� �� �������������� ���� � �������� �����.
*	������, ����������� ������ ��������� ������ ������������� �� ������ ������� ������
*	QWidget ��� �� ���� ������.
*
*		����� ���������� ������� ����������, ����� ����� ������ ������ �������������
*	��������� �������:
*
*	@code
*
*	void penChanged( const QPen &pen ); //������ �������������� �� ����� ��������� �
*						//���������� �����. ���������� ������ ������������ ����� ���������.
*
*	@endcode
*/
class PenEditorInterface
{
	public:
		/**
		*	������ ���������� ������� ���������.
		*/
		virtual QPen pen() const = 0;

		/**
		*	��������� ��������� �������� ����� ���������������.
		*/
		virtual void setPen( const QPen &p ) = 0;

		/**
		*	�����������.
		*/
		PenEditorInterface() {};

		/**
		*	����������.
		*/
		virtual ~PenEditorInterface() {};
};

Q_DECLARE_INTERFACE( PenEditorInterface, "com.alxn1.sacs2.PenEditorInterface/1.0" )

/**
*		�������� ��������� �� ����� ������ � ���������� �� ��������� PenEditorInterface �,
*	���� ���������� ������ �������, �������� ����� pen().
*
*	@param o ����������������, ��������� �� ������, ����������� ��������� PenEditorInterface.
*
*	@return ������� ��� � ��������� �����.
*/
template < class T > inline QPen GET_PEN( T *o )
{
	PenEditorInterface *i = qobject_cast< PenEditorInterface* >( o );
	if( i == 0 ) return QPen();
	return i->pen();
}

/**
*		�������� ��������� �� ����� ������ � ���������� �� ��������� PenEditorInterface �,
*	���� ���������� ������ �������, �������� ����� setPen().
*
*	@param o ����������������, ��������� �� ������, ����������� ��������� PenEditorInterface.
*	@param p ��������������� ��� � ��������� �����.
*/
template < class T > inline void SET_PEN( T *o, const QPen &p )
{
	PenEditorInterface *i = qobject_cast< PenEditorInterface* >( o );
	if( i == 0 ) return;
	return i->setPen( p );
}

/**
*	�������� ��������� �� ����� ������ � ���������� �� ��������� PenEditorInterface.
*
*	@return ���������� ��������� ��� 0, ���� ��������� ������.
*/
template < class T > inline PenEditorInterface* PENEDITOR( T *o )
{
	return qobject_cast< PenEditorInterface* >( o );
}

#endif /* __PEN_EDITOR_INTERFACE_H__ */
