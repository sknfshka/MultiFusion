#ifndef __BRUSH_INTERFACE_H__
#define __BRUSH_INTERFACE_H__

#include <QRect>
#include <QBrush>
#include <QMatrix>
#include <QPainter>
#include "GradientEditorInterface.h"

/**
*	@file brusheditorinterface.h � ������ ����� ������ ���������, ������� ������ �������������
*		����� ������, ���������� �� �������������� ���� � �������� �������.
*/

/**
*		���������, ������� ������ �������������
*	����� ������, ���������� �� �������������� ���� � �������� �������.
*	������, ����������� ������ ��������� ������ ������������� �� ������ ������� ������
*	QWidget ��� �� ���� ������.
*
*		��� ��������� ���������, ���� ��� �������� ����������� ���� qreal � ����� ����������
*	� ����������� �� ��������� ������������� ������� ��� � �������, ������ ������������
*	��������� [0..1].
*
*		����� ���������� ������� ����������, ����� ����� ������ ������ �������������
*	��������� �������:
*
*	@code
*
*	void brushChanged( const QBrush &brush ); //������ �������������� �� ����� ��������� �
*					//���������� �������. ���������� ������ ������������ ����� ���������.
*
*	@endcode
*/
class BrushEditorInterface:public QWidget
{
	public:
		/**
		*	������ ���������� ������� ���������.
		*/
		virtual QBrush brush() const = 0;

		/**
		*	��������� ��������� �������� ����� ���������������.
		*/
		virtual void setBrush( const QBrush &b ) = 0;

				/**
				*	�����������.
				*/
				 BrushEditorInterface() {};

		/**
		*	����������.
		*/
		virtual ~BrushEditorInterface() {};
};

Q_DECLARE_INTERFACE( BrushEditorInterface, "com.alxn1.sacs2.BrushEditorInterface/1.0" )

/**
*		�������� ��������� �� ����� ������ � ���������� �� ��������� BrushEditorInterface �,
*	���� ���������� ������ �������, �������� ����� brush().
*
*	@param o ����������������, ��������� �� ������, ����������� ��������� BrushEditorInterface.
*
*	@return ������� ��� � ��������� �������.
*/
template < class T > inline QBrush GET_BRUSH( T *o )
{
	BrushEditorInterface *i = qobject_cast< BrushEditorInterface* >( o );
	if( i == 0 ) return QBrush();
	return i->brush();
}

/**
*		�������� ��������� �� ����� ������ � ���������� �� ��������� BrushEditorInterface �,
*	���� ���������� ������ �������, �������� ����� setBrush().
*
*	@param o ����������������, ��������� �� ������, ����������� ��������� BrushEditorInterface.
*	@param b ��������������� ��� � ��������� �������.
*/
template < class T > inline void SET_BRUSH( T *o, const QBrush &b )
{
	BrushEditorInterface *i = qobject_cast< BrushEditorInterface* >( o );
	if( i == 0 ) return;
	return i->setBrush( b );
}

/**
*	�������� ��������� �� ����� ������ � ���������� �� ��������� BrushEditorInterface.
*
*	@return ���������� ��������� ��� 0, ���� ��������� ������.
*/
template < class T > inline BrushEditorInterface* BRUSHEDITOR( T *o )
{
	return qobject_cast< BrushEditorInterface* >( o );
}

/**
*		�������������� ��������� ����� �� �������������� ��� ���������.
*	��� ��������� ���������, ���� ��� �������� ����������� ���� qreal � ����� ����������
*	� ����������� �� ��������� ������������� ������� ��� � �������, ����� ��������� ��
*	��������� [0..1] � ���������, ������������ ��� �������� ������������� �������.
*
*	@param b ���������, ������� ���������� �����������.
*	@param rect �������, ������� ���������� ������, ���������� ��� ���������.
*/
inline QBrush prepareBrushToPaint( const QBrush &b, const QRect &rect )
{
	switch( b.style() )
	{
		case Qt::LinearGradientPattern:
		case Qt::ConicalGradientPattern:
		case Qt::RadialGradientPattern:
			return prepareGradientToPaint( *b.gradient(), rect );
			break;

		case Qt::TexturePattern:
		{
			QMatrix m;
			QPoint pos = rect.topLeft();
			m.translate( pos.x(), pos.y() );
			QBrush brush( b );
			brush.setMatrix( m );
			return brush;
			break;
		}

		default:
			break;
	}

	return b;
}

/**
*		�������������� ��������� ����� �� �������������� ��� ��������������.
*	��� ��������� ���������, ���� ��� �������� ����������� ���� qreal � ����� ����������
*	� ����������� �� ��������� ������������� ������� ��� � �������, ����� ��������� �
*	��������� [0..1].
*
*	@param b ���������, ������� ���������� �����������.
*	@param rect �������, ������� �� ����� �������� � ������� ������ ��������.
*/
inline QBrush prepareBrushToEdit( const QBrush &b, const QRect &rect )
{
	switch( b.style() )
	{
		case Qt::LinearGradientPattern:
		case Qt::ConicalGradientPattern:
		case Qt::RadialGradientPattern:
			return prepareGradientToEdit( *b.gradient(), rect );
			break;

		case Qt::TexturePattern:
		{
			QMatrix m;
			QPoint pos = rect.topLeft();
			m.translate( -pos.x(), -pos.y() );
			QBrush brush( b );
			brush.setMatrix( m );
			return brush;
			break;
		}

		default:
			break;
	}

	return b;
}

#endif /* __BRUSH_INTERFACE_H__ */
