/**
* GVFInterface.h
*
*  Created on: 27.04.2009
*      Author: Alexey Kukushkin
*/

#ifndef GVFINTERFACE_H_
#define GVFINTERFACE_H_

#include <QObject>
#include "../gobject.h"

/**
*		�����, ����������� ��������� ������,
*			�������� �� �����.
*/
class GVFInterface:public GObject
{

	public:
		/**
		*	������� ���� � ��������� �������, ���� ���� ���� ����������.
		*
		*	@param frame ����� ���������� �����.
		*/
		virtual void deleteFrame( int frame );

		/**
		*	��������� ���� � ����� ������.
		*
		*	@param empty ���� �������� ���������� � true, �� ����� �������� ������ ����,
		*		� ��������� ������ ����� ���������� ���������� ������ ���� (���� �� ����).
		*/
		virtual void addFrameToBegin( bool empty = false );

		/**
		*	��������� ���� � ����� �����.
		*
		*	@param empty ���� �������� ���������� � true, �� ����� �������� ������ ����,
		*		� ��������� ������ ����� ���������� ���������� ��������� ���� (���� �� ����).
		*/
		virtual void addFrameToEnd( bool empty = false );

		/**
		*	��������� ���� ����� ���������� ������������� �����.
		*
		*	@param frame ����, ����� �������� ����� �������� �����.
		*	@param empty ���� �������� ���������� � true, �� ����� �������� ������ ����,
		*		� ��������� ������ ����� ���������� ��������� ���� (���� �� ����).
		*/
		virtual void addFrameAfter( int frame, bool empty = false );

		/**
		*	��������� ���� ����� ��������� ������������ ������.
		*
		*	@param frame ����, ����� ������� ����� �������� �����.
		*	@param empty ���� �������� ���������� � true, �� ����� �������� ������ ����,
		*		� ��������� ������ ����� ���������� ��������� ���� (���� �� ����).
		*/
		virtual void addFrameBefore( int frame, bool empty = false );

		/**
		*	��������� ��������� ���� � ��������� ��� ����� ����������.
		*
		*	@param frame ����, ������� ���������� ������������.
		*	@param pasteTo ����, ����� �������� ����� �������� ����� ����.
		*/
		virtual void cloneFrameBefore( int frame, int pasteTo );

		/**
		*	��������� ��������� ���� � ��������� ��� ����� ���������.
		*
		*	@param frame ����, ������� ���������� ������������.
		*	@param pasteTo ����, ����� ������� ����� �������� ����� ����.
		*/
		virtual void cloneFrameAfter( int frame, int pasteTo );

		/**
		*	���������� ��� �������������� ����� �������.
		*
		*	@return ��� �������������� �����.
		*/
		virtual GLinesType type() const;


		/**
		*	���������� true, ���� � ������ ������ ������ ����� �������������.
		*
		*	@return true, ���� � ������ ������ ������ ����� �������������.
		*/
		virtual bool isEditable() const;


		/**
		*	���������� true, ���� ������ �������� �����������.
		*
		*	@return true, ���� ������ �������� �����������.
		*/
		virtual bool isContainer() const;

		/**
		*	���������� true, ���� ������ � ������ ������ ����� ������ �� ������.
		*
		*	@return true, ���� ������ � ������ ������ ����� ������ �� ������.
		*/
		virtual bool isVisible() const;

		/**
		*	������������� ��������� �������.
		*
		*	@param visible ��������� �������.
		*/
		virtual void setVisible( bool visible );


		/**
		*	���������� ��������� �� ������, ������� �������� ������ �����.
		*
		*	@param p ��������� �����, �� ������� ���������� ���������� ������.
		*
		*	@return ��������� �� ������, ������� �������� ������ �����.
		*
		*	@warning ���� �� ���� ������ � ���������� �� �������� ��� �����,
		*		�� ����� ��������� 0.
		*/
		virtual GObject* contains( const QPoint &p );


		/**
		*	���������� ������� ������� ������� � �������� (������� ����).
		*
		*	@return ������� ������� ������� � �������� (������� ����).
		*/
		virtual qreal frame() const;

		/**
		*	������������ ������� ���� ��� �������.
		*
		*	@param f ��������������� ����.
		*/
		virtual void setFrame( qreal f );

		/**
		*	���������� ����� ���������� ������, ������� ��� ������� ��� ����� �������.
		*
		*	@return ����� ���������� ������, ������� ��� ������� ��� ����� �������.
		*/
		virtual int countFrames() const;


		/**
		*	���������� ���������� ��������������, � ������� ������ ������ ������.
		*
		*	@return ���������� ��������������, � ������� ������ ������ ������.
		*/
		virtual QRectF boundingRect() const;

		/**
		*	���������� ��� �����, �� ������� ������� ������ ������.
		*
		*	@return �����, �� ������� ������� ������ ������.
		*/
		virtual QPolygonF points() const;

		/**
		*	��������� ����� ����� � ������.
		*
		*	@param p ���������� ����������� �����.
		*
		*	@return ������ ��������������� �����.
		*/
		virtual int addPoint( const QPoint &p );

		/**
		*	��������� ����� ����� � ������, �� ��������� ��������� ��������� ������ ������� -
		*		�.�. ����� ������ ����������� � ����� ������.
		*
		*	@param p ���������� ����������� �����.
		*
		*	@return ������ ��������������� �����.
		*/
		virtual int addPointToEnd( const QPoint &p );

		/**
		*	������� ����� �� � ������� �� �������.
		*
		*	@param index ������ ��������� �����.
		*
		*	@return true, ���� ����� ���� �������.
		*/
		virtual bool deletePoint( int index );

		/**
		*	���������� ���� �� ����� ������ �� ����� �����.
		*
		*	@param index ������ ������������ �����.
		*	@param newPosition ����� ��������� �����.
		*/
		virtual void movePoint( int index, const QPointF &newPosition );

		/**
		*	��������� ���� �� ������ ����� �������, ��� �� �������� ��� ��������� �����.
		*
		*	@param frame ����������� ����.
		*/
		virtual void cloneFrameToAll( int frame );


		/**
		*	���������� ����������� ������� �������.
		*
		*	@param dx �������� �� ��� X.
		*	@param dy �������� �� ��� Y.
		*/
		virtual void move( qreal dx, qreal dy );

		/**
		*	���������� ��������������� �������.
		*
		*	@param sx ����������� ��������������� �� ��� X.
		*	@param sy ����������� ��������������� �� ��� Y.
		*	@param scaleCenter �����, ������������ ������� ������������ ��������������.
		*/
		virtual void scale( qreal sx, qreal sy, const QPointF &scaleCenter );

		/**
		*	���������� ����������� ����� ��������� ����� �������.
		*
		*	@param sx ����������� ������ �� ��� X.
		*	@param sy ����������� ������ �� ��� Y.
		*	@param scaleCenter �����, ������������ ������� ������������ �����
		*					(�.�., ����������, �����, ������� �� ���������� �����).
		*/
		virtual void sheare( qreal sx, qreal sy, const QPointF &shearPoint );

		/**
		*	���������� �������� ������.
		*
		*	@param angle ����, �� ������� ������������ �������.
		*	@param center �����, ������ ������� ������������ �������.
		*/
		virtual void rotate( qreal angle, const QPointF &center );

		/**
		*	���������� ��� � ��������� ����� �������.
		*
		*	@return ��� � ��������� ����� �������.
		*/
		virtual QPen pen() const;

		/**
		*	���������� ��� � ��������� ������� �������.
		*
		*	@return ��� � ��������� ������� �������.
		*/
		virtual QBrush brush() const;

		/**
		*	������������� ��� � ��������� ����� �������.
		*
		*	@param p ��� � ��������� ����� �������.
		*/
		virtual void setPen( const QPen &p );

		/**
		*	������������� ��� � ��������� ������� �������.
		*
		*	@param p ��� � ��������� ������� �������.
		*/
		virtual void setBrush( const QBrush &b );

		/**
		*	��������� ������ �� �����������.
		*
		*	@return true, ���� ������ ��������.
		*/
		virtual bool isClosed() const;

		/**
		*	������������� ����������� ������.
		*
		*	@param closed ����������� ������.
		*/
		virtual void setClosed( bool _closed );

		/**
		*	��������� �������� ������������ ������.
		*
		*	@return �������� ������������(�� 0 �� 255%).
		*/
		virtual int getAlpha();

		/**
		*	����� ������������ ������.
		*
		*	@param _alpha �������� ������������(�� 0 �� 255).
		*/
		virtual void setAlpha( int _alpha );

		/**
		*	������������ ������� ���� ������.
		*
		*	@param p ��, ���� ����� ������������ ���������.
		*/
		virtual void paint( QPainter &p ) const;

		/**
		*	�����������.
		*/
		GVFInterface( ) = 0;

		/**
		*	����������.
		*/
		virtual ~GVFInterface();

	protected:

		/**
		*	��������� ���� ������ ������� � �����.
		*
		*	@param stream �����, � ������� ����������� ������.
		*/
		virtual void save( QDataStream &stream ) const;

		/**
		*	������ ���� ������ ������� �� ������.
		*
		*	@param stream �����, �� �������� ���������� ������.
		*/
		virtual void load( QDataStream &stream );

	private:
		GFramesProperties properties;
		qreal _frame;
		GLinesType	_linesType;
		QPen alphaPen;
		QBrush alphaBrush;
		QPen _pen;
		QBrush _brush;
		bool closed;

		virtual GProperties currentFrame() const;
		virtual void paintObject( QPainter &p, const GProperties &props ) const;

		void drawSplines( QPainter &p, const GProperties &props ) const;

		QPen interpolatedPen() const;
		QBrush interpolatedBrush() const;

		int addPointToPolygon( const QPointF &p );
		int addPointToEndOfPolygon( const QPointF &p );
		int addPointToSpline( const QPointF &p );
};


Q_DECLARE_INTERFACE( GVFInterface, "com.Tailer.MultiFusion.GVFInterface/1.0" )


#endif /* GVFINTERFACE_H_ */
