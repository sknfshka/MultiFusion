#ifndef __BACKGROUND_INTERFACE_H__
#define __BACKGROUND_INTERFACE_H__

#include <QDataStream>
#include <QPainter>
#include <QColor>
#include <QRect>

/**
*	@file backgroundinterface.h � ������ ����� ������ ���������, ������� ������ �������������
*		����� ������, ���������� �� ��������� ������� ���� � GCore � �� ��������������
*		��� ��������.
*/

/**
*		���������, ������� ������ �������������
*	����� ������, ���������� �� ��������� ������� ���� � GCore � �� ��������������
*	��� ��������.
*
*		����� ���������� ������� ����������, ����� ����� ������ ������ �������������
*	��������� �������:
*
*	@code
*
*	void changed(); //������ �������������� �� ����� ��������� � ���������� ����.
*
*	@endcode
*/
class BackgroundInterface
{
	public:

		/**
		 * ������ ����� ������� �������
		 */
		virtual QObject* copyBackground() = 0;

		/**
		*	����� �������� �������.
		*/
		virtual void reset() = 0;

		/**
		*	���������� �������� ������� � �����.
		*
		*	@param stream �����, � ������� ������������ ������.
		*/
		virtual void save( QDataStream &stream ) const = 0;

		/**
		*	������ �������� ������� �� ������.
		*
		*	@param stream �����, �� �������� ���������� ������.
		*/
		virtual void load( QDataStream &stream ) = 0;

		/**
		*		������ ���������� ������, ����������� ��������� �������. ������, ������ � ������
		*	������ ���� ��������. �.�. ����� ��������� �������� � ������ ������� ������ �����-��
		*	����������� �� ����� �������.
		*
		*	@return ������, ����������� ��������� �������.
		*/
		virtual QWidget *editor() = 0;

		/**
		*		������ ������ ������������ ��� ������� ������� ���� ��������. ��� ����������������
		*	������ ��������������� � ������� ������� ������.
		*
		*	@param p ��, ���� ������������ ���������.
		*	@param rect ������������� �������, ������� ���������� ���������.
		*/
		virtual void fill( QPainter &p, QRect rect ) const = 0;

				/**
				*	�����������.
				*/
				 BackgroundInterface() {};

		/**
		*	����������.
		*/
		virtual ~BackgroundInterface() {};
};

Q_DECLARE_INTERFACE( BackgroundInterface, "com.alxn1.sacs2.BackgroundInterface/1.0" )

/**
*		�������� ��������� �� ����� ������ � ���������� �� ��������� BackgroundInterface �,
*	���� ���������� ������ �������, �������� ����� fill().
*
*	@param o ����������������, ��������� �� ������, ����������� ��������� BackgroundInterface.
*	@param p ��, ���� ����� ������������ ���������.
*	@param rect ������������� �������, ������� ����� ���������.
*/
template < class T > inline void FILL( T *o, QPainter &p, QRect rect )
{
	BackgroundInterface *i = qobject_cast< BackgroundInterface* >( o );
	if( i == 0 ) return;
	i->fill( p, rect );
}

/**
*		�������� ��������� �� ����� ������ � ���������� �� ��������� BackgroundInterface �,
*	���� ���������� ������ �������, �������� ����� editor().
*
*	@param o ����������������, ��������� �� ������, ����������� ��������� BackgroundInterface.
*
*	@return ��������� �� ������, ����������� ��������� ������� �������. � 0, ���� ���-�� ���������
*		������, ��� �������� ��� �� ��������������.
*/
template < class T > inline QWidget* GET_EDITOR( T *o )
{
	BackgroundInterface *i = qobject_cast< BackgroundInterface* >( o );
	if( i == 0 ) return 0;
	return i->editor();
};

/**
*	�������� ��������� �� ����� ������ � ���������� �� ��������� BackgroundInterface.
*
*	@return ���������� ��������� ��� 0, ���� ��������� ������.
*/
template < class T > inline BackgroundInterface* BACKGROUND( T *o )
{
	return qobject_cast< BackgroundInterface* >( o );
}

#endif /* __BACKGROUND_INTERFACE_H__ */
