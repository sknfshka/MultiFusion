/**
* RPWInterface.h
*
*  Created on: 23.04.2009
*      Author: Alexey Kukushkin
*/

#ifndef RPWINTERFACE_H_
#define RPWINTERFACE_H_
#include <QApplication>
#include <QWidget>
#include <QRect>
#include <QAction>
#include <QTimer>
#include <QSize>
#include <QObject>
#include <QMenu>
#include <QtOpenGL/QGLWidget>

class RPWInterface:public QGLWidget
{
	signals:
		void figureSelected(int layer , int obj);
		void layerSelected( int layer );
		void frameChanged( qreal frame );
		void objectCreated();
		void isPlayed();
		
		/**
		 * ������������ ��� ����������� �� ������� �������
		 */
		void undoEvents();

		void StateChanged(QString event);

	public slots:
		/**
		* ��������� ������������ �������
		* @param _alpha
		*/
		virtual void alphaChanged(int _alpha) = 0;
		/**
		* ��������� ���� � ���������������� �������
		*/
		virtual void onPropertiesObj() = 0;
	public:

		/**
		 * ���������� ������� �������
		 */
		virtual QObject* getUndo() = 0;

		/**
		 * ������ ��������� RealPaintWidget �� ���������� �� ������� �������
		 * @param undo ������� �������
		 */
		virtual void setFromUndo(QObject* undo) =0 ;

		virtual void paintEvent( QPaintEvent * event ) = 0;
		virtual void mousePressEvent( QMouseEvent *event ) = 0;
		virtual void mouseMoveEvent( QMouseEvent * event ) = 0;
		virtual void mouseReleaseEvent( QMouseEvent * event ) = 0;
		virtual void mouseDoubleClickEvent( QMouseEvent * event ) = 0;
		virtual void resizeEvent( QResizeEvent * event ) = 0;

		virtual void setFrame( qreal f , bool played) = 0;
		virtual qreal frame() const = 0;
		virtual int countFrames() const = 0;
		virtual void paintFrameTo( QPainter &to, const QRect &r, qreal frame ) = 0;
		//virtual void paintWholeFrameTo( QPainter &to, const QRect &r, qreal frame ) = 0;

		/**��������� ����� ����
		 *
		 * @param visible ��������� ����
		 * @param blocked ���������� ����
		 * @param name ��� ����
		 */
		virtual void addLayer(bool visible, bool blocked, const QString &name) = 0;

		/**
		* ������� ������������� ����
		* @param qMenu
		*/
        virtual void setContextMenu(QMenu *qMenu) = 0;

		/**
		* ��������� ������������� ����
		* @return
		*/
        virtual QMenu* getContextMenu() = 0;

		virtual QObject* getBackground() = 0;

		virtual void setBackground(QObject* back) = 0;

		virtual bool getFixedSize() = 0;

		virtual void setFixedSize(bool back) = 0;

		virtual QSize getSize() = 0;

		virtual void setSize(QSize sz) = 0;

		/** ��������� ������� ��� ������ � ���������� - ����� GSelectionRect
		*
		* @return
		*/
		virtual QObject* getSelection() = 0;

		virtual void setSelection(QObject* s) = 0;

		virtual QObject* getCurrentTool() = 0;

		virtual void setCurrentTool(QObject* ct) = 0;

		virtual QAction* getPropertiesAct() = 0;

		virtual void setPropertiesAct(QAction* pa) = 0;

		virtual bool getInKeyPressedHandler() = 0;

		virtual void setInKeyPressedHandler(bool kph) = 0;

		virtual bool getInSelectionMode() = 0;

		virtual void setInSelectionMode(bool sm) = 0;

		virtual QRect getSelectionRect() = 0;

		virtual void setSelectionRect(QRect sr) = 0;

		RPWInterface( QWidget *parent ):QGLWidget(QGLFormat(QGL::SampleBuffers), parent ){};
		virtual ~RPWInterface(){};


};

Q_DECLARE_INTERFACE( RPWInterface, "com.alxn1.sacs2.RPWInterface/1.0" )

template < class T > inline RPWInterface * RPWINTEFACE( T *o )
{
	return qobject_cast< RPWInterface* >( o );
}

#endif /* RPWINTERFACE_H_ */
