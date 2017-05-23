/**
* PaintWidgetInterface.h
*
*  Created on: 23.04.2009
*      Author: Alexey Kukushkin
*/

#ifndef PAINTWIDGETINTERFACE_H_
#define PAINTWIDGETINTERFACE_H_

#include <QApplication>
#include <QMenu>
#include <QObject>
#include <QScrollArea>

class PaintWidgetInterface:public QScrollArea
{
	signals:

		void zoomEvent(qreal scale);
		void paintEvent(QPoint origin);
        void mouseMoveEvent(QPoint origin, QPoint global, qreal scale);
	
		 /**
		 * ������������ ����� ���������� �������, ������� ��� ����� ��������� � �������
		 * @param event ��� �������
		 */
		void StateChanged(QString event);

		/**
		 * ������������ ��� ����������� �� ������� �������
		 */
		void undoEvents();

		/**
		* ������������ ��� ����������� ���� ��� ������
		*/
		void movedObject();

		/**
		*	������������ � ������ �������� ������ ������.
		*/
		void objectCreated();

		/**
		*	������������ ������ ���, ����� ��������� ������� ������������ ����.
		*
		*	@param frame ����� ������� ����.
		*/
		void frameChanged( qreal frame );

		/**
		*	������������ ������ ���, ����� ���������� ����� ���������� ������ � ��������.
		*/
		void countFramesChanged( int count );

		/**
		*	������������ ������ ��� ��� �������� ���������.
		*
		*	@param layer ����� ���������� ����, ��� -1, ���� �� ���� ���� �� ������.
		*/
		void layerSelected( int layer );

		/**
		*		���������� � ��� ������, ����� ��������� ���������� ��������� ����
		*	(��������, ��� ���� ��� �������).
		*/
		void allLayersChanged();

		/**
		*		������ ��� ����������� �������������, ���������� � ��� ������, ����� ����������
		*	��������� ������� ���� ��� ������� �������.
		*/
		void backgroundChanged( QWidget *from );

		void figureSelected(int layer , int obj);

	public:
	
		virtual void scrollContentsBy(int dx, int dy) = 0;
		virtual void mouseMoveEvent( QMouseEvent * event ) = 0;
		virtual void paintEvent( QPaintEvent * event) = 0;
		virtual void mySetViewportMargins(int left, int top, int right, int bottom)=0;
	
		/**
		 * ������ �������� ������ � ������� ���� ��� ���
		 */
		virtual void setHideFigures(int layer, bool value)=0;

		/**
		 * ��������� �������� ������ � ������� ���� ��� ���
		 */
		virtual bool getHideFigures(int layer)=0;

		/**
		 * �������� ����� ����� ���������� ����� ����� ������ �����
		 * @return ���������� �����
		 */
		virtual int getFigureHideLines() = 0;

		/**
		 * ����� ����� ����� ���������� ����� ����� ������ �����
		 * @param value ���������� �����
		 */
		virtual void setFigureHideLines(int value) = 0;

		/**
		 * ��������� �������� �� ������ � ����������
		 * @return 1 ���� ��, 0 ���� ��� -1 ���� ��� ���������
		 */
		virtual int FigureIsSpline() = 0;

		/**
		 * ��������� ������ � ���������� ����� ��� ���������� � ���������� �� spline
		 */
		virtual void FigureSetStyle(bool spline) = 0;

		/**
		 * ����� ��������� ��� ������ ����� ����� ��� ���
		 * @param value true ���� ����������
		 */
		virtual void FigureSetShowBezier(bool value) = 0;

		/**
		 * ����� ��������� ��� ������ ����� ����� ��� ���
		 * @return 1 ���� ��, 0 ���� ��� -1 ���� ��� ���������
		 */
		virtual int FigureIsShowBezier() = 0;

		/**
		 * ���������� ������������ ����
		 */
		virtual int maxFrame() = 0;

		/**
		 * ��������� ���� �� � ������� ������� ��������� ���� ��� ������� ����
		 * @param layer ������ ����
		 */
		virtual bool isContainsFrame(int layer) = 0;

		/**
		 * 	���������� ������� ����� �� ���������
		 * @param i ������� � ������
		 * @return ������� �� ���������
		 */
		virtual int getPositionFrame(int i) = 0;

		/**
		*	���������� 3 ���� ������������� ������������/������������� ������.
		*/
		enum ViewportType
		{
			fixedViewport,		/** ����� ����� ������������� ������ � ������. ����� �� ������� �� �����������. */
			resizableViewport, 	/** ����� �� ����� ������������� �������� � ������� �� ������/������ ���� ���������.. */
			hintViewport		/** ����� ����� ������������� ������ � ������. ����� �� ������� �����������. */
		};


		/**
		*	������������� ������� ���� ��������.
		*
		*	@param frame ��������������� ���� ��������.
		*/
		virtual void setFrame( qreal frame, bool played ) = 0;

		/**
		*	���������� ������� ���� ��������.
		*
		*	@return ������� ���� ��������.
		*/
		virtual int frame() const = 0;

		/**
		*	���������� ������� ����.
		*
		*	@return ������� ����.
		*/
		virtual int layer() const = 0;

		/**
		*	���������� ����� ���������� ������, ������������ � ������.
		*/
		virtual int countFrames() const = 0;

		/**
		*	������������ ������� ����.
		*
		*	@param s ����������� ���������������.
		*
		*	@warning �������������� ������ ������� ����.
		*/
		virtual void scale( qreal s ) = 0;

		/**
		*	��������� �� ����������� ����������� ���������� ��������.
		*
		*	@return true, ���� ����������� ��������.
		*/
		virtual bool canGroup() = 0;

		/**
		*	��������� �� ����������� �������������� ���������� ��������.
		*
		*	@return true, ���� �������������� ��������.
		*/
		virtual bool canUngroup() = 0;

		/**
		*	���������� ���������� �������, ���� ��� ��������.
		*/
		virtual void group() = 0;

		/**
		*	����������������� ���������� �������, ���� ��� ��������.
		*/
		virtual void ungroup() = 0;

		/**
		*	���������� ��� � ��������� ����� ����������� �������.
		*
		*	@return ��� � ��������� ����� ����������� �������.
		*/
		virtual QPen pen() = 0;

		/**
		*	���������� ��� � ��������� ������� ����������� �������.
		*
		*	@return ��� � ��������� ������� ����������� �������.
		*/
		virtual QBrush brush() = 0;

		/**
		*	������������� ��� � ��������� ����� ����������� �������.
		*
		*	@param p ��� � ��������� ����� ����������� �������.
		*/
		virtual void setPen( const QPen &p ) = 0;

		/**
		*	������������� ��� � ��������� ������� ����������� �������.
		*
		*	@param p ��� � ��������� ������� ����������� �������.
		*/
		virtual void setBrush( const QBrush &b ) = 0;

		/**
		*	��������� ���������� ������ �� �����������.
		*
		*	@return true, ���� ������ ��������.
		*/
		virtual bool isClosed() const = 0;

		/**
		*	������������� ����������� ���������� ������.
		*
		*	@param closed ����������� ������.
		*/
		virtual void setClosed( bool closed ) = 0;

		/**
		 * �������� �������� �� ������ �����������
		 * @param layer ���� � ������� ��������� ������
		 * @param object ������
		 */
		virtual bool objectIsContainer(int layer, int object) = 0;

		/**
		*	���������� ������� ���������� �������� � ���� layer.
		*/
		virtual int countFigures(int layer) const = 0;

		/**
		*	���������� ��� �������.
		*
		*	@param layer ����, ������� �������� ������.
		*
		*	@param object ������.
		*/
		virtual QString figureName( int layer, int object  ) const = 0;

		/**
		 * ������ ��� ������ � ����
		 * @param layer - ����� ����
		 * @param obj - ����� ������
		 * @param name ���
		 */
		virtual void renameFigure( int layer, int obj,  const QString &name ) = 0;

		/**
		*	��������� ��������� ������ �� ���������������.
		*
		*	@param layer ����, ������� �������� ������.
		*
		*	@param object ������, ����������� �� ���������������.
		*/
		virtual bool isFigureBlocked(  int layer, int object  ) const = 0;

		/**
		 * ������ ��������������� ������ � ����
		 * @param layer - ����� ����
		 * @param obj - ����� ������
		 * @param visible �������� ����������
		 */
		virtual void setFigureBlocked( int layer, int obj, bool blocked ) = 0;

		/**
		*	��������� ��������� ������ �� ��������� �� ������.
		*
		*	@param layer ����, ������� �������� ������.
		*
		*	@param object ������, ����������� �� ���������.
		*/
		virtual bool isFigureVisible(  int layer, int object  ) const = 0;

		/**
		 * ������ ��������� ������ � ����
		 * @param layer - ����� ����
		 * @param obj - ����� ������
		 * @param visible �������� ���������
		 */
		virtual void setFigureVisible( int layer, int obj, bool visible ) = 0;

		/**
		 * ��������� �������� �� ������ ����������������
		 * @param layer ���� � ������� ��������� ������
		 * @param object ����� ������
		 * @return true ���� ���������������
		 */
		virtual bool isFigureTransformed(  int layer, int object  ) const = 0;

		/**
		 * ���������� ������������������ ������
		 * @param layer ���� � ������� ��������� ������
		 * @param object ����� ������
		 * @param trns �������� ������������������
		 */
		virtual void setFigureTransformed( int layer, int obj, bool trns ) = 0;

		/**
		*	���������� ����� ���������� ����. ��� -1, ���� �� ��������� ��� �� ������.
		*
		*	@return ����� ���������� ����. ��� -1, ���� �� ��������� ��� �� ������.
		*/
		virtual int selectedFigure() = 0;

		/**
		*	������������� ��������� �� ��������� ���� � ��������� ������
		*
		*	@param layer ���������� ����.
		*
		*	@param obj ���������� ������.
		*/
		virtual void selectFigure( int layer, int obj) = 0;

		/**
		 * ������� ������ �� ����
		 * @param layer - ����� ����
		 * @param obj - ����� ������
		 */
		virtual void deleteFigure(int layer, int obj ) = 0;

		                /**
                 * ��������� ������ � ������� ����, �������� �� �� ���������� ����������
                 * @param poly - �����: �� ������� �������� ������
                 * @param pen - ����
                 * @param brush - �����
                 * @param name - �������� ������
                 * @param select - �������� �� ������ ����� ����������
                 */
                virtual void addFigure(const QPolygonF &poly, QPen pen, QBrush brush, QString name, bool select) = 0;
		
		/**
		 * ��������� ����� ����
		 */
		virtual void addLayer(bool visible, bool blocked, const QString &name) = 0;

		/**
		*	���������� ������� ���������� ����.
		*
		*	@return ������� ���������� ����.
		*/
		virtual int countLayers() const = 0;

		/**
		 * ������ ������� ����.
		 */
		virtual void setLayer(int layer) = 0;

		/**
		*	���������� ��� ���������� ����.
		*
		*	@param layer ����, ��� �������� �������������.
		*
		*	@return ��� �������������� ����.
		*/
		virtual QString layerName( int layer ) = 0;

		/**
		*	��������������� ��������� ����.
		*
		*	@param layer ����.
		*	@param name ����� ��� ����.
		*/
		virtual void renameLayer( int layer, const QString &name ) = 0;

		/**
		*	��������� ��������� ���� �� ��������������� �� ������.
		*
		*	@param layer ����, ����������� �� ���������������.
		*
		*	@return true, ���� ���� ����������.
		*/
		virtual bool isLayerBlocked( int layer ) const = 0;

		/**
		*	������������� ��������������� ���������� ���� � ������ �����.
		*
		*	@param layer ����.
		*	@param blocked ��������������� ���� � ������ �����.
		*/
		virtual void setLayerBlocked( int layer, bool blocked ) = 0;

		/**
		*	��������� ��������� ���� �� ��������� �� ������.
		*
		*	@param layer ����, ����������� �� ���������.
		*
		*	@return true, ���� ���� �����.
		*/
		virtual bool isLayerVisible( int layer ) const = 0;

		/**
		*	������������� ��������� ���������� ���� � ������ �����.
		*
		*	@param layer ����.
		*	@param visible ��������� ���� � ������ �����.
		*/
		virtual void setLayerVisible( int layer, bool visible ) = 0;

		/**
		*	���������� ����� ���������� ����. ��� -1, ���� �� ������.
		*
		*	@return ����� ���������� ����. ��� -1, ���� �� ������.
		*/
		virtual int selectedLayer() = 0;

		/**
		*	������� ���� �� �������.
		*/
		virtual void deleteFrame(int position) = 0;

		/**
		 * ��������� ���� � ����������� �������
		 * @param position
		 */
		virtual void addFrame(int position) = 0;

		/**
		*		������������� ����������, ���������� �� ����� �������� � �� �� �����������
		*	(����������� �����), ��� �������.
		*/
		virtual void setSelectionTool() = 0;

		/**
		*		������������� ����������, ���������� �� ���������� ����� �
		*	��������� ������, ��� �������.
		*/
		virtual void setAddPointTool() = 0;

		/**
		*	������������� ����� ����������, ��� �������.
		*
		*	@param tool ������, ����������� ��������� �����������.
		*/
		virtual void setTool( QObject *tool ) = 0;


		/**
		*	������������� ��������� ���� �������� ����.
		*
		*	@param to ��� ��, ���� ����� ��������� ����������� ����.
		*	@param r �������������, � ������� ����� �������������� ����.
		*	@param frame ����, ������� ����� ���������.
		*/
		virtual void paintFrameTo( QPainter &to, const QRect &r, qreal frame ) = 0;

		/**
		*	������������� ��������� ����.
		*
		*	@param to ��� ��, ���� ����� ��������� ����������� ����.
		*	@param r �������������, � ������� ����� �������������� ����.
		*	@param frame ����, ������� ����� ���������.
		*/
		//virtual void paintWholeFrameTo( QPainter &to, const QRect &r, qreal frame ) = 0;

		/**
		*		���������� ����� ������������� ��������.
		*	��������� ��� �������, �� ������� ������� ��������.
		*/
		virtual bool reset() = 0;

		/**
		*	��������� ��������� ������� � �����.
		*
		*	@param stream �����, � ������� ������������ ������.
		*/
		virtual void save( QDataStream &stream ) = 0;

		/**
		*	��������� ��������� ������� �� ������.
		*
		*	@param stream �����, �� �������� �������� ��������.
		*/
		virtual bool load( QDataStream &stream ) = 0;

		/**
		*	��������� ����������� �������� ��������� ��������.
		*
		*	@return true, ���� ��� ��������.
		*/
		virtual bool canDeleteSelected() const = 0;

		/**
		*	������� ��������� �������, ���� ��� ��������.
		*/
		virtual void deleteSelected() = 0;

		/**
		*	��������� ����������� ����������� ��� �������� � ������ ������ ��������� �������.
		*
		*	@return true, ���� ��� ��������.
		*/
		virtual bool canCopyOrCutToClipboard() const = 0;

		/**
		*	��������� ����������� �������� ������ �� ������� ������.
		*
		*	@return true, ���� ��� ��������.
		*/
		virtual bool canPasteFromClipboard() const = 0;

		/**
		*	�������� � ������ ������ ���������� �������, ���� ��� ��������.
		*/
		virtual void cutToClipboard() = 0;

		/**
		*	�������� � ������ ������ ���������� �������, ���� ��� ��������.
		*/
		virtual void copyToClipboard() = 0;

		/**
		*	��������� �� ������� ������ �������, ���� ��� ��������.
		*/
		virtual void pasteFromClipboard() = 0;

		/**
		*	����� ������������ ���� ��� ������� ���������.
		*	@*qMenu - ����������� ������������ ����
		*/
        virtual void setContextMenu(QMenu *qMenu) = 0;

		/**
		*	�������� ������������ ���� ��� ������� ���������.
		*	@return - ��������� �� ������������ ����
		*/
        virtual QMenu* getContextMenu() = 0;

		/**
		*	�������� ������ �������� ������� �������. ��������.
		*/
		virtual void showConfig() = 0;

		/**
		*	���������� ��� ������������� ������������/������������� ������.
		*
		*	@return ��� ������������� ������������/������������� ������.
		*/
		virtual ViewportType viewportType()const = 0;

		virtual void setViewportType( const ViewportType t )= 0;

		virtual QObject* getRealPaintWidget() = 0;

		///virtual void setRealPaintWidget(QObject* rpw) = 0;

		/**virtual void setViewportColor( const QColor &c ) = 0;

		virtual QColor& getViewportColor() = 0;

		virtual QSize viewportFixedSize() const = 0;

		virtual void setViewportFixedSize( const QSize &s ) = 0;*/

		virtual void doViewportTransparent() = 0;

		virtual void updateAllViews( QWidget *from ) = 0;

		/**
		*	�����������.
		*
		*	@param parent ������������ ��� ������� ������� ������.
		*		����� ��������� �������� 0.
		*
		*	@param manager �������� ��������. ��������� ��� ��������
		*		Background � BrushEditor ��� ����� ������ Background.
		*/
		PaintWidgetInterface(QWidget *parent):QScrollArea(parent)
		{

		}

		/**
		*	����������.
		*/
		virtual ~PaintWidgetInterface(){};

	public slots:
		/**
		 *  ���������� ������ ����� ������ � ������ ���� �� �������
		 */
		void moveFigure( int layerOld, int objOld, int layerNew, int objNew );
		/**
		 *  ���������� ���� �� �������
		 */
		void moveLayer(int layerOld, int layerNew);
};


Q_DECLARE_INTERFACE( PaintWidgetInterface, "com.alxn1.sacs2.PaintWidgetInterface/1.0" )

template < class T > inline PaintWidgetInterface * PAINTWIDGETINTERFACE( T *o )
{
	return qobject_cast< PaintWidgetInterface* >( o );
}

#endif
