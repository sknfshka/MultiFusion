/**
 * GObjectInterface.h
 *
 *  Created on: 24.04.2009
 *      Author: Alexey Kukushkin
 */

#ifndef GOBJECTINTERFACE_H_
#define GOBJECTINTERFACE_H_
#include <QApplication>
#include <QObject>
#include "FigureToolInterface.h"

class GObjectInterface:public QObject
{
	public:

		/**
		*	���������� ��� ���������� ����� �������.
		*/
		enum GLinesType
		{
			gNormal, /** ����� ����� ��������� ������� */
			gSplines /** ����� ����� ��������� ��������� */
		};

		/**
		 *  ����������� �������� �������
		 */
		virtual GObjectInterface* copyObject()=0;

		/**
		*	��������� ���� �� �������.
		*
		*	@param position - ������� �� ���������;
		*/
		virtual void addFrame( int position ,bool visible) = 0;

		/**
		 * ������� ��� ����� ����� frame
		 * @param frame, ���� ����� -1 ������� ��������� ��� �����
		 */
		virtual void deleteFrames( int frame ) = 0;

		/**
		*	������� ���� � ��������� �������, ���� ���� ���� ����������.
		*
		*	@param frame ����� ���������� �����.
		*/
		virtual void deleteFrame( int position ) = 0;

		/**
		*	��������� ��������� ���� � ��������� ��� ����� ����������.
		*
		*	@param frame ����, ������� ���������� ������������.
		*	@param pasteTo ����, ����� �������� ����� �������� ����� ����.
		*/
		virtual void cloneFrameBefore( int frame, int pasteTo ) = 0;

		/**
		*	��������� ��������� ���� � ��������� ��� ����� ���������.
		*
		*	@param frame ����, ������� ���������� ������������.
		*	@param pasteTo ����, ����� ������� ����� �������� ����� ����.
		*/
		virtual void cloneFrameAfter( int frame, int pasteTo ) = 0;


		/**
		*	���������� ��� �������������� ����� �������.
		*
		*	@return ��� �������������� �����.
		*/
		virtual GLinesType type() const = 0;

		/**
		*	���������� true, ���� � ������ ������ ������ ����� �������������.
		*
		*	@return true, ���� � ������ ������ ������ ����� �������������.
		*/
		virtual bool isEditable() const = 0;


		/**
		*	���������� true, ���� ������ �������� �����������.
		*
		*	@return true, ���� ������ �������� �����������.
		*/
		virtual bool isContainer() const = 0;

		/**
		*	���������� true, ���� ������ � ������ ������ ����� ������ �� ������.
		*
		*	@return true, ���� ������ � ������ ������ ����� ������ �� ������.
		*/
		virtual bool isVisible() const = 0;

		/**
		*	������������� ��������� �������.
		*
		*	@param visible ��������� �������.
		*/
		virtual void setVisible( bool visible ) = 0;

		/**
		*	���������� true, ���� ������ � ������ ������ ����������.
		*
		*	@return true, ���� ������ � ������ ������ ����������
		*/
		virtual bool isBlocked() const = 0;

		/**
		*	������������� ���������� �������.
		*
		*	@param blocked ���������� �������.
		*/
		virtual void setBlocked( bool blocked ) = 0;

		/**
		*	���������� ������� ������� ������� � �������� (������� ����).
		*
		*	@return ������� ������� ������� � �������� (������� ����).
		*/
		virtual qreal frame() const = 0;

		/**
		*	������������ ������� ���� ��� �������.
		*
		*	@param f ��������������� ����.
		*/
		virtual void setFrame( qreal f ) = 0;


		/**
		*	���������� ����� ���������� ������, ������� ��� ������� ��� ����� �������.
		*
		*	@return ����� ���������� ������, ������� ��� ������� ��� ����� �������.
		*/
		virtual int countFrames() const = 0;


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
		virtual GObjectInterface* contains( const QPoint &p ) = 0;

		/**
		*	���������� ���������� ��������������, � ������� ������ ������ ������.
		*
		*	@return ���������� ��������������, � ������� ������ ������ ������.
		*/
		virtual QRectF boundingRect() = 0;
		/**
		*	��������� �������� ������������ ������.
		*
		*	@return �������� ������������(�� 0 �� 255%).
		*/
		virtual int getAlpha() = 0;

		/**
		*	����� ������������ ������.
		*
		*	@param _alpha �������� ������������(�� 0 �� 255).
		*/
		virtual void setAlpha( int _alpha ) = 0;
		/**
		*	���������� ����������� ������� �������.
		*
		*	@param dx �������� �� ��� X.
		*	@param dy �������� �� ��� Y.
		*/

		virtual void move( qreal dx, qreal dy ) = 0;

		/**
		*	���������� ��������������� �������.
		*
		*	@param sx ����������� ��������������� �� ��� X.
		*	@param sy ����������� ��������������� �� ��� Y.
		*	@param scaleCenter �����, ������������ ������� ������������ ��������������.
		*/
		virtual void scale( qreal sx, qreal sy, const QPointF &scaleCenter ) = 0;

		/**
		*	���������� ����������� ����� ��������� ����� �������.
		*
		*	@param sx ����������� ������ �� ��� X.
		*	@param sy ����������� ������ �� ��� Y.
		*	@param scaleCenter �����, ������������ ������� ������������ �����
		*					(�.�., ����������, �����, ������� �� ���������� �����).
		*/
		virtual void sheare( qreal sx, qreal sy, const QPointF &shearPoint ) = 0;

		/**
		*	���������� �������� ������.
		*
		*	@param angle ����, �� ������� ������������ �������.
		*	@param center �����, ������ ������� ������������ �������.
		*/
		virtual void rotate( qreal angle, const QPointF &center ) = 0;


		/**
		*	���������� ��� �����, �� ������� ������� ������ ������.
		*
		*	@return �����, �� ������� ������� ������ ������.
		*/
		virtual QPolygonF points(int frame) = 0;

		/**
		*	��������� ����� ����� � ������.
		*
		*	@param p ���������� ����������� �����.
		*
		*	@return ������ ��������������� �����.
		*/
		virtual int addPoint( const QPoint &p ) = 0;

		/**
		*	��������� ����� ����� � ������, �� ��������� ��������� ��������� ������ ������� -
		*		�.�. ����� ������ ����������� � ����� ������.
		*
		*	@param p ���������� ����������� �����.
		*
		*	@return ������ ��������������� �����.
		*/
		virtual int addPointToEnd( const QPoint &p ) = 0;

		/**
		*	������� ����� �� � ������� �� �������.
		*
		*	@param index ������ ��������� �����.
		*
		*	@return true, ���� ����� ���� �������.
		*/
		virtual bool deletePoint( int index ) = 0;

		/**
		*	���������� ���� �� ����� ������ �� ����� �����.
		*
		*	@param index ������ ������������ �����.
		*	@param newPosition ����� ��������� �����.
		*/
		virtual void movePoint( int index, const QPointF &newPosition ) = 0;

		/**
		*	��������� ���� �� ������ ����� �������, ��� �� �������� ��� ��������� �����.
		*
		*	@param frame ����������� ����.
		*/
		virtual void cloneFrameToAll( int frame ) = 0;


		/**
		*	���������� ��� � ��������� ����� �������.
		*
		*	@return ��� � ��������� ����� �������.
		*/
		virtual QPen pen() const = 0;

		/**
		*	���������� ��� � ��������� ������� �������.
		*
		*	@return ��� � ��������� ������� �������.
		*/
		virtual QBrush brush() const = 0;

		/**
		*	������������� ��� � ��������� ����� �������.
		*
		*	@param p ��� � ��������� ����� �������.
		*/
		virtual void setPen( const QPen &p ) = 0;

		/**
		*	������������� ��� � ��������� ������� �������.
		*
		*	@param p ��� � ��������� ������� �������.
		*/
		virtual void setBrush( const QBrush &b ) = 0;

		/**
		*	��������� ������ �� �����������.
		*
		*	@return true, ���� ������ ��������.
		*/
		virtual bool isClosed() const = 0;

		/**
		*	������������� ����������� ������.
		*
		*	@param closed ����������� ������.
		*/
		virtual void setClosed( bool closed ) = 0;

		/**
		*	������������ ������� ���� ������.
		*
		*	@param p ��, ���� ����� ������������ ���������.
		*/
		virtual void paint( QPainter &p ) = 0;

		/**
		*	��������� � ����� ����� ������ ����������� ��������.
		*
		*	@param stream �����, � ������� ���������� ������.
		*	@param o ������, ������� ����������� � �����. �� ����� ���� ����� ����������� ��������,
		*			���� �����������. ���� �����������, � ������� ��������� ����������. � �.�.
		*			������� ����������� ������������.
		*/
		static void saveObject( QDataStream &stream, const GObjectInterface *o );

		/**
		*		��������� � ������ �� ������ ����� ���������� ����������� ������. (��� ������
		*	��������.)
		*
		*	@param stream �����, �� �������� ���������� ������.
		*
		*	@return ������������� ������, ������� ��� �� ����� ������� � ���, ������ ����������
		*		������ ������. ���� ����� �� �������� ��������, ������� ����� ���������,
		*		������������ 0.
		*/
		static GObjectInterface *loadObject( QDataStream &stream );

		/**
		*		������ ����� ����������� ������ �� ���������� �� ������� � ������ ����������� ������
		*	� � ������ �����.
		*
		*	@param info ���������� � ������, �� ������ ������� �������� ������.
		*	@param countFrames �� ���������� ������, � �������� ����� ������ ������.
		*	@param pos �������, � ������� ����� ������ ������.
		*/
		static GObjectInterface *create( QObject* figureTool,
				 const QPointF &pos, int number, int positon);

		/**
		*		������ ����� ����������� ������ �� ���������� �� ������� � ������ ����������� ������
		*	� � ������ �����. ���� ���������� �������� �������� ���������� ��������, �� ���
		*	����� ������� � �������� � ���������. � ����� ��������� ��������� �� ����.
		*
		*	@param info ���������� � ������, �� ������ ������� �������� ������.
		*	@param countFrames �� ���������� ������, � �������� ����� ������ ������.
		*	@param pos �������, � ������� ����� ������ ������.
		*	@param name ��� ����������, ���� �� ����� ������.
		*/
		static GObjectInterface *create( QObject* figureTool,
				 const QPointF &pos,const QString &name, int position );
		/**
		*	��������� ���� ������ ������� � �����.
		*
		*	@param stream �����, � ������� ����������� ������.
		*/
		virtual void save( QDataStream &stream ) const = 0;

		/**
		*	������ ���� ������ ������� �� ������.
		*
		*	@param stream �����, �� �������� ���������� ������.
		*/
		virtual void load( QDataStream &stream ) = 0;

		/**
		*	�����������.
		*/
		GObjectInterface(){};

		/**
		*	����������
		*/
		virtual ~GObjectInterface() {};

};

Q_DECLARE_INTERFACE( GObjectInterface, "com.Tailer.MultiFusion.GObjectInterface/1.0" )

template < class T > inline GObjectInterface * GOBJECTINTEFACE( T *o )
{
	return qobject_cast< GObjectInterface* >( o );
}
#endif /* GOBJECTINTERFACE_H_ */
