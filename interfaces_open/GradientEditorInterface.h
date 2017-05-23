#ifndef __GRADIENT_EDITOR_INTERFACE_H__
#define __GRADIENT_EDITOR_INTERFACE_H__

#include <QRect>
#include <QLineF>
#include <QMatrix>
#include <QGradient>
#include <QWidget>
/**
*	@file gradienteditorinterface.h � ������ ����� ������ ���������, ������� ������ �������������
*		����� ������, ���������� �� �������������� ���� � �������� ���������.
*/

/**
*		���������, ������� ������ �������������
*	����� ������, ���������� �� �������������� ���� � �������� ���������.
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
*	void gradientChanged( const QGradient &gradient ); //������ �������������� �� ����� ��������� �
*									//���������� ���������. ���������� ������ ������������ ����� ���������.
*
*	@endcode
*/
class GradientEditorInterface:public QWidget
{
	public:
		/**
		*	������ ���������� ������� ���������.
		*/
		virtual QGradient gradient() const = 0;

		/**
		*	��������� ��������� �������� ����� ���������������.
		*/
		virtual void setGradient( const QGradient &g) = 0;

				/**
				*	�����������.
				*/
				 GradientEditorInterface() {};

		/**
		*	����������.
		*/
		virtual ~GradientEditorInterface() {};
};

Q_DECLARE_INTERFACE( GradientEditorInterface, "com.alxn1.sacs2.GradientEditorInterface/1.0" )

/**
*		�������� ��������� �� ����� ������ � ���������� �� ��������� GradientEditorInterface �,
*	���� ���������� ������ �������, �������� ����� gradient().
*
*	@param o ����������������, ��������� �� ������, ����������� ��������� GradientEditorInterface.
*
*	@return ������� ��� � ��������� ���������.
*/
template < class T > inline QGradient GET_GRADIENT( T *o )
{
	GradientEditorInterface *i = qobject_cast< GradientEditorInterface* >( o );
	if( i == 0 ) return QGradient();
	return i->gradient();
}

/**
*		�������� ��������� �� ����� ������ � ���������� �� ��������� GradientEditorInterface �,
*	���� ���������� ������ �������, �������� ����� setGradient().
*
*	@param o ����������������, ��������� �� ������, ����������� ��������� GradientEditorInterface.
*	@param g ��������������� ��� � ��������� ���������.
*/
template < class T > inline void SET_GRADIENT( T *o, const QGradient &g )
{
	GradientEditorInterface *i = qobject_cast< GradientEditorInterface* >( o );
	if( i == 0 ) return;
	return i->setGradient( g );
}

/**
*	�������� ��������� �� ����� ������ � ���������� �� ��������� GradientEditorInterface.
*
*	@return ���������� ��������� ��� 0, ���� ��������� ������.
*/
template < class T > inline GradientEditorInterface* GRADIENTEDITOR( T *o )
{
	return qobject_cast< GradientEditorInterface* >( o );
}

/**
*		�������������� ��������� ����� �� ��������������.
*	��� ��������� ���������, ���� ��� �������� ����������� ���� qreal � ����� ����������
*	� ����������� �� ��������� ������������� ������� ��� � �������, ����� ��������� ��
*	��������� [0..1] � ���������, ������������ ��� �������� ������������� �������.
*
*	@param g ���������, ������� ���������� �����������.
*	@param rect �������, ������� ���������� ������, ���������� ��� ���������.
*/
inline QGradient prepareGradientToPaint( const QGradient &g, const QRect &rect )
{
	QGradient ret;

	switch( g.type() )
	{
		case QGradient::LinearGradient:
		{
			QLinearGradient &pointer =  ( ( QLinearGradient& ) g );
			ret = QLinearGradient( QPointF( rect.x() + pointer.start().x() * ( rect.width() - 1 ),
											rect.y() + pointer.start().y() * ( rect.height() - 1 ) ),
									QPointF( rect.x() + pointer.finalStop().x() * ( rect.width() - 1 ),
											rect.y() + pointer.finalStop().y() * ( rect.height() - 1 ) ) );
			break;
		}

		case QGradient::RadialGradient:
		{
			QRadialGradient &pointer =  ( ( QRadialGradient& ) g );

			QPointF start = QPointF( rect.x() + pointer.center().x() * ( rect.width() - 1 ),
									rect.y() + pointer.center().y() * ( rect.height() - 1 ) );

			QPointF end = QPointF( 	rect.x() + pointer.focalPoint().x() * ( rect.width() - 1 ),
									rect.y() + pointer.focalPoint().y() * ( rect.height() - 1 ) );

			qreal radius = qreal( qMin( rect.width(), rect.height() ) / 2.0 );

			QLineF l( start, end );
			if( l.length() > radius )
				l.setLength( radius - 1 );

			ret = QRadialGradient( l.p1(), radius, l.p2() );
			break;
		}

		default:
		{
			QConicalGradient &pointer =  ( ( QConicalGradient& ) g );
			QPointF point = ( QLineF( 0.0, 0.0, 1.0, 0.0 ) *
								QMatrix().rotate( pointer.angle() ) ).p2();
			point.rx() *= ( rect.width() - 1 );
			point.ry() *= ( rect.height() - 1 );

			QLineF l( QPointF( 0.0, 0.0 ), point );
			l.setLength( 1.0 );
			qreal a = l.angle( QLineF( 0.0, 0.0, 1.0, 0.0 ) );
			if( l.dy() > 0 )
            	a = 360 - a;

			ret = QConicalGradient( QPointF( rect.x() + pointer.center().x() * ( rect.width() - 1 ),
									rect.y() + pointer.center().y() * ( rect.height() - 1 ) ), a );
			break;
		}
	}

	ret.setStops( g.stops() );
	ret.setSpread( g.spread() );

	return ret;
}

/**
*		�������������� ��������� ����� �� �������������� ��� ��������������.
*	��� ��������� ���������, ���� ��� �������� ����������� ���� qreal � ����� ����������
*	� ����������� �� ��������� ������������� ������� ��� � �������, ����� ��������� �
*	��������� [0..1].
*
*	@param g ���������, ������� ���������� �����������.
*	@param rect �������, ������� �� ����� �������� � ������� ������ ��������.
*/
inline QGradient prepareGradientToEdit( const QGradient &g, const QRect &rect )
{
	if( ( rect.width() == 0 ) || ( rect.height() == 0 ) )
		return g;

	QGradient ret;

	switch( g.type() )
	{
		case QGradient::LinearGradient:
		{
			QLinearGradient &pointer =  ( ( QLinearGradient& ) g );
			ret = QLinearGradient( QPointF( ( pointer.start().x() - rect.x() ) / ( rect.width() - 1 ),
											( pointer.start().y() - rect.y() ) / ( rect.height() - 1 ) ),
									QPointF( ( pointer.finalStop().x() - rect.x() ) / ( rect.width() - 1 ),
											( pointer.finalStop().y() - rect.y() ) / ( rect.height() - 1 ) ) );
			break;
		}

		case QGradient::RadialGradient:
		{
			QRadialGradient &pointer =  ( ( QRadialGradient& ) g );

			QPointF start = QPointF( ( pointer.center().x() - rect.x() ) / ( rect.width() - 1 ),
									( pointer.center().y() - rect.y() ) / ( rect.height() - 1 ) );

			QPointF end = QPointF( 	( pointer.focalPoint().x() - rect.x() ) / ( rect.width() - 1 ),
									( pointer.focalPoint().y() - rect.y() ) / ( rect.height() - 1 ) );

			qreal radius = qreal( qMin( rect.width(), rect.height() ) / 2.0 );

			QLineF l( start, end );
			if( l.length() > radius )
				l.setLength( radius - 1 );

			ret = QRadialGradient( l.p1(), radius, l.p2() );
			break;
		}

		default:
		{
			QConicalGradient &pointer =  ( ( QConicalGradient& ) g );

			ret = QConicalGradient( QPointF( ( pointer.center().x() - rect.x() ) / ( rect.width() - 1 ),
									( pointer.center().y() - rect.y() ) / ( rect.height() - 1 ) ), pointer.angle() );
			break;
		}
	}

	ret.setStops( g.stops() );
	ret.setSpread( g.spread() );

	return ret;
}

#endif /* __GRADIENT_EDITOR_INTERFACE_H__ */
