#ifndef __COLOR_EDITOR_INTERFACE_H__
#define __COLOR_EDITOR_INTERFACE_H__

#include <QColor>
#include <QWidget>

//;
/**
*	@file coloreditorinterface.h � ������ ����� ������ ���������, ������� ������ �������������
*		����� ������, ���������� �� �������������� �����.
*/

/**
*		���������, ������� ������ �������������
*	����� ������, ���������� �� �������������� �����.
*	������, ����������� ������ ��������� ������ ������������� �� ������ ������� ������
*	QWidget ��� �� ���� ������.
*
*		����� ���������� ������� ����������, ����� ����� ������ ������ �������������
*	��������� �������:
*
*	@code
*
*	void colorChanged( const QColor newColor ); //������ �������������� �� ����� ��������� �
*									//�����. ���������� ������ ������������ ����� ����.
*
*	@endcode
*/
class ColorEditorInterface:public QWidget
{
	public:
		/**
		*	������ ���������� ������� ����.
		*/
		virtual QColor color() const = 0;

		/**
		*	��������� ���������� ����� ����� ���������������.
		*/
		virtual void setColor( const QColor newColor ) = 0;

				/**
				*	�����������.
				*/
				 ColorEditorInterface() {};

		/**
		*	����������.
		*/
		virtual ~ColorEditorInterface() {};
};

Q_DECLARE_INTERFACE( ColorEditorInterface, "com.alxn1.sacs2.ColorEditorInterface/1.0" )

/**
*		�������� ��������� �� ����� ������ � ���������� �� ��������� ColorEditorInterface �,
*	���� ���������� ������ �������, �������� ����� color().
*
*	@param o ����������������, ��������� �� ������, ����������� ��������� ColorEditorInterface.
*
*	@return ������� ����.
*/
template < class T > inline QColor GET_COLOR( T *o )
{
	ColorEditorInterface *i = qobject_cast< ColorEditorInterface* >( o );
	if( i == 0 ) return QColor();
	return i->color();
}

/**
*		�������� ��������� �� ����� ������ � ���������� �� ��������� ColorEditorInterface �,
*	���� ���������� ������ �������, �������� ����� set�olor().
*
*	@param o ����������������, ��������� �� ������, ����������� ��������� ColorEditorInterface.
*	@param c ��������������� ����.
*/
template < class T > inline void SET_COLOR( T *o, const QColor &c )
{
	ColorEditorInterface *i = qobject_cast< ColorEditorInterface* >( o );
	if( i == 0 ) return;
	return i->setColor( c );
}

/**
*	�������� ��������� �� ����� ������ � ���������� �� ��������� ColorEditorInterface.
*
*	@return ���������� ��������� ��� 0, ���� ��������� ������.
*/
template < class T > inline ColorEditorInterface* COLOREDITOR( T *o )
{
	return qobject_cast< ColorEditorInterface* >( o );
}

#endif /* __COLOR_EDITOR_INTERFACE_H__ */
