﻿#ifndef __GCONTAINER__H__
#define __GCONTAINER__H__

#include <QVector>
#include "GObject.h"
#include "../interfaces/GObjectInterface.h"

/**
*	@file gcontainer.h Данный файл содержит описание класса, реализующего контейнер,
*			который может содержать различные графические элементы. В том числе и сами
*			контейнеры, так как этот класс является наследником класса GObject. Глубина
*			вложенности, естественно, не ограничена.
*/

/**
*		Класс, реализующий контейнер,
*	который может содержать различные графические элементы. В том числе и сами
*	контейнеры, так как этот класс является наследником класса GObject. Глубина
*	вложенности, естественно, не ограничена.
*/
class GContainer:public GObject
{
	Q_OBJECT

    public:
        virtual int rewriteLastPointGuideCoord( const QPoint &p ){return 0;}
        virtual void deleteLastGuide() {}
        virtual void reestablishLastGuid();
		/*
		*	Специфичные методы для контейнера.
		*/

		/**
		 *  Копирование текущего объекта
         */
		virtual GObjectInterface* copyObject();

		/**
		*		Возвращает имя обькта, находящегося в данном контейнере,
		*	по его индексу.
		*
		*	@param index индекс обьекта, имя которого необходимо узнать.
		*
		*	@return имя обькта.
		*/
		virtual QString objectName( int index ) const;

		/**
		*		Устанавливает имя обькта, находящегося в данном контейнере,
		*	по его индексу.
		*
		*	@param index индекс обьекта, имя которого необходимо узнать.
		*	@param name новое имя обькта.
		*/
		virtual void setObjectName( int index, const QString &newName );

		/**
		*	Возвращает количество обьектов, уже находящихся в данном контейнере.
		*
		*	@return количество обьктов, находящихся в данном контейнере.
		*/
		virtual int countObjects() const;

		/**
		*	Добавляет новый обьект в контейнер.
		*
		*	@param o добавляемый в контейнер обьект.
		*	@param realChild если данный параметр выставить в true, то при
		*				вызове деструктора контейнера будут удалён и добавляемый обьект.
		*				По-умолчанию он имеет значение false.
		*
		*	@return индекс внутри контейнера нового обьекта.
		*/
		virtual int add( GObject *o, bool realChild = false );

		/**
		*		"Вынимает" обьект из контейнера. Сам обьект не удаляется,
		*	однако в контейнере он больше не присутствует.
		*
		*	@param index индекс "вынимаемого" обьекта.
		*
		*	@return указатель на вынимаемый обьект. Если обьект больше не нужен, и он
		*		был создан с помощью оператора new, то обьект можно сразу ужалить
		*		с помощью delete:
		*	@code
		*		delete containr->remove( 10 );
		*	@endcode
		*
		*	@warning Если обьекта с этим индексом не существует, то возвращается 0.
		*/
		virtual GObject* remove( int index );

		/**
		*		"Вынимает" сразу все бьекты из контейнера. Все они перестают в нём находится,
		*	однако не удаляются.
		*
		*	@return вектор, содержащий все обьекты, которые ранее находились в этом контейнере.
		*			В том случае, если в контейнере не было ни одного обьекта, возвращается пустой вектор.
		*/
		virtual QVector< GObject* > removeAll();

		/**
		*	Проверяет на наличие некоторого обьекта внутри данного контейнера.
		*
		*	@param o обьект, который предположительно находится/не находится в контейнере.
		*
		*	@return true, если в этом контейнере обьект присутствует.
		*/
		virtual bool isInside( GObject *o );

		/**
		*	Возвращает индект обьекта, находящегося в контейнере, по указателю на него.
		*
		*	@param o указатель на обьект, индекс которого необходимо выяснить.
		*
		*	@return индект обьекта. Или -1, если такой обьект в контейнере не присутствует.
		*/
		virtual int objectIndex( GObject *o );

		/**
		*	Возвращает указатель на обьект, находящийся в контейнере, по его индексу.
		*
		*	@param index индекс обьекта
		*
		*	@return указатель на обьект с запрошенным индексом.
		*
		*	@warning если обькта с запрошенным индексом нет, метод возвращает 0.
		*/
		virtual GObject* object( int index );

		/**
		*		Сдвигает обькт с требуемым индексом на один уровень вниз внутри контейнера.
		*	При этом, естественно, меняется индекс изменяемого обьекта.
		*
		*	@param index индекс обьекта.
		*
		*	@return новый индекс этого обьекта.
		*/
		virtual int moveDown( int index );

		/**
		*		Сдвигает обькт с требуемым индексом на один уровень вверх внутри контейнера.
		*	При этом, естественно, меняется индекс изменяемого обьекта.
		*
		*	@param index индекс обьекта.
		*
		*	@return новый индекс этого обьекта.
		*/
		virtual int moveUp( int index );

		/**
		*		Сдвигает обькт с требуемым индексом на самый верх внутри контейнера.
		*	При этом, естественно, меняется индекс изменяемого обьекта.
		*
		*	@param index индекс обьекта.
		*
		*	@return новый индекс этого обьекта.
		*/
		virtual int moveToFirst( int index );

		/**
		*		Сдвигает обькт с требуемым индексом на самый низ внутри контейнера.
		*	При этом, естественно, меняется индекс изменяемого обьекта.
		*
		*	@param index индекс обьекта.
		*
		*	@return новый индекс этого обьекта.
		*/
		virtual int moveToLast( int index );

		/**
		*		Сдвигает обькт с требуемым индексом на требуемое место внутри контейнера.
		*	При этом, естественно, меняется индекс изменяемого обьекта.
		*
		*	@param index индекс обьекта.
		*
		*	@return новый индекс этого обьекта.
		*/
		virtual int move( int index, const int to );

		/*
		*	Странно, но иначе не работает...
		*/

		/**
		*	Возвращает имя обьекта контейнера.
		*
		*	@return имя обьекта контейнера.
		*/
		virtual QString objectName() const
		{
			return GObjectInterface::objectName();
		}

		/**
		*	Устанвливает новое имя обекта контейнера.
		*
		*	@param name новое имя.
		*/
		virtual void setObjectName( const QString &name )
		{
			GObjectInterface::setObjectName( name );
		}

		/*
		*	Методы, реализующие интерфейс GObjectInterface.
		*/

		/**
		 * Удаляет все кадры кроме frame
		 * @param frame, если равен -1 удаляет абсолютно все кадры
		 */
		virtual void deleteFrames( int frame );

		/**
		*	Удаляет кадр с требуемым номером, если этот кадр существует.
		*
		*	@param frame номер удаляемого кадра.
		*/
		virtual void deleteFrame( int position );

		/**
		*	Добавляет кадр по позиции.
		*
		*	@param position - позиция на таймлайне;
		*/
		virtual void addFrame( int position, bool visible);

		/**
		*	Клонирует выбранный кадр и вставляет его после указанного.
		*
		*	@param frame кадр, который необходимо склонировать.
		*	@param pasteTo кадр, после которого будет вставлен новый кадр.
		*/
		virtual void cloneFrameBefore( int frame, int pasteTo );

		/**
		*	Клонирует выбранный кадр и вставляет его перед указанным.
		*
		*	@param frame кадр, который необходимо склонировать.
		*	@param pasteTo кадр, перед которым будет вставлен новый кадр.
		*/
		virtual void cloneFrameAfter( int frame, int pasteTo );


		/**
		*	Возвращает тип соединительных линий первого (!!!) из обьектов, находящихся в контейнере.
		*
		*	@return тип соединительных линий.
		*/
		virtual GObject::GLinesType type() const;

		/**
		*	Возвращает true, если в данный момент обьект можно редактировать.
		*
		*	@return true, если в данный момент обьект можно редактировать.
		*/
		virtual bool isEditable() const;

		/**
		*	Возвращает true, если обьект является контейнером.
		*
		*	@return true, если обьект является контейнером.
		*/
		virtual bool isContainer() const;

		/**
		*	Получение значения прозрачности фигуры.
		*
		*	@return значение прозрачности(от 0 до 255%).
		*/
		virtual int getAlpha();

		/**
		*	Задаёт прозрачность фигуры.
		*
		*	@param _alpha значение прозрачности(от 0 до 255).
		*/
		virtual void setAlpha( int _alpha );

		/**
		*	Возвращает true, если обьект в данный момент блокирован.
		*
		*	@return true, если обьект в данный момент блокирован
		*/
		virtual bool isBlocked() const;

		/**
		*	Устанавливает блокировку объекта.
		*
		*	@param blocked блокировка объекта.
		*/
		virtual void setBlocked( bool blocked );

		/**
		*		Проверяет на блокировку обьект, находящийся в контейнере, с заданным интексом.
		*
		*	@param index индекс обьекта, имя которого необходимо узнать.
		*
		*	@return true, если обьект блокирован и false в противном случае.
		*/
		virtual bool isObjectBlocked( int index ) const;

		/**
		*		Устанавливает блокировку обьекта, находящегося в контейнере, с заданным интексом.
		*
		*	@param index индекс обьекта, имя которого необходимо узнать.
		*	@param visible блокировка обьекта.
		*/
		virtual void setObjectBlocked( int index, bool blocked );

		/**
		*		Проверяет на видимость обьект, находящийся в контейнере, с заданным интексом.
		*
		*	@param index индекс обьекта, имя которого необходимо узнать.
		*
		*	@return true, если обьект можно видеть и false в противном случае.
		*/
		virtual bool isObjectVisible( int index ) const;

		/**
		*		Устанавливает видимость обьекта, находящегося в контейнере, с заданным интексом.
		*
		*	@param index индекс обьекта, имя которого необходимо узнать.
		*	@param visible видимость обьекта.
		*/
		virtual void setObjectVisible( int index, bool visible );

		/**
		*	Возвращает true, если обьект в данный момент можно видеть на экране.
		*
		*	@return true, если обьект в данный момент можно видеть на экране.
		*/
		virtual bool isVisible() const;

		/**
		*	Устанавливает видимость обьекта.
		*
		*	@param visible видимость обьекта.
		*/
		virtual void setVisible( bool visible );

		/**
		*	Возвращает указатель на обьект, который содержит данную точку.
		*
		*	@param p кординаты точки, по которой необходимо определить обьект.
		*
		*	@return указатель на обьект, который содержит данную точку.
		*
		*	@warning если ни один обьект в контейнере не содержит эту точку,
		*		то будет возвращён 0.
		*/
		virtual GObject* contains( const QPoint &p );

		/**
		*	Возвращает текущую позицию обьекта в анимации (текущий кадр).
		*
		*	@return текущую позицию обьекта в анимации (текущий кадр).
		*/
		virtual qreal frame() const;

		/**
		*	Устанвливает текущий кадр для обьекта.
		*
		*	@param f устанавливаемый кадр.
		*/
		virtual void setFrame( qreal f );

		/**
		*	Возвращает общее количество кадров, которое уже заданно для этого обьекта.
		*
		*	@return общее количество кадров, которое уже заданно для этого обьекта.
		*/
		virtual int countFrames() const;

		/**
		*	Возвращает координаты прямоугольника, в который вписан данный обьект.
		*
		*	@return координаты прямоугольника, в который вписан данный обьект.
		*/
		virtual QRectF boundingRect();

		/**
		*	Удаляет точку по её индексу из обьекта.
		*
		*	@param index индекс удаляемой точки.
		*
		*	@return true, если точка была удалена.
		*/
		virtual bool deletePoint( int index );

		/**
		*	Добавляет новую точку в фигуру.
		*
		*	@param p координаты добавляемой точки.
		*
		*	@return индекс новодобавленной точки.
		*/
		virtual int addPoint( const QPoint &p );

		/**
		*	Добавляет новую точку в фигуру, не используя различный алгоритмы выбора позиции -
		*		т.е. точка всегда добавляется в конец фигуры.
		*
		*	@param p координаты добавляемой точки.
		*
		*	@return индекс новодобавленной точки.
		*/
		virtual int addPointToEnd( const QPoint &p );

		/**
		*	Производит паралельный перенос обьекта.
		*
		*	@param dx смещение по оси X.
		*	@param dy смещение по оси Y.
		*/
		virtual void move( qreal dx, qreal dy );

		/**
		*	Производит масштабирование обьекта.
		*
		*	@param sx коэффициент масштабирования по оси X.
		*	@param sy коэффициент масштабирования по оси Y.
		*	@param scaleCenter точка, относительно которой производится масштаирование.
		*/
		virtual void scale( qreal sx, qreal sy, const QPointF &scaleCenter );

		/**
		*	Производит паралельный сдвиг некоторой грани обьекта.
		*
		*	@param sx коэффициент сдвига по оси X.
		*	@param sy коэффициент сдвига по оси Y.
		*	@param scaleCenter точка, относительно которой производится сдвиг
		*					(т.е., собственно, точка, лежащая на сдвигаемой грани).
		*/
		virtual void sheare( qreal sx, qreal sy, const QPointF &shearPoint );

		/**
		*	Производит вращение фигуры.
		*
		*	@param angle угол, на который производится поворот.
		*	@param center точка, вокруг которой производится поворот.
		*/
		virtual void rotate( qreal angle, const QPointF &center );

		/**
		*	Возвращает все точки, из которых состоит данная фигура.
		*
		*	@return точки, из которых состоит данная фигура.
		*/
		virtual QPolygonF points(int frame);

		/**
		*	Перемещает одну из точек фигуры на новое место.
		*
		*	@param index индекс перемещаемой точки.
		*	@param newPosition новое положение точки.
		*/
		virtual void movePoint( int index, const QPointF &newPosition );

		/**
		*	Клонирует один из кадров таким образом, что он замещает все остальные кадры.
		*
		*	@param frame клонируемый кадр.
		*/
		virtual void cloneFrameToAll( int frame );

		/**
		*	Возвращает тип и параметры линий обьекта.
		*
		*	@return тип и параметры линий обьекта.
		*/
		virtual QPen pen() const;

		/**
		*	Возвращает тип и параметры заливки обьекта.
		*
		*	@return тип и параметры заливки обьекта.
		*/
		virtual QBrush brush() const;

		/**
		*	Устанавливает тип и параметры линий обьекта.
		*
		*	@param p тип и параметры линий обьекта.
		*/
		virtual void setPen( const QPen &p );

		/**
		*	Устанавливает тип и параметры заливки обьекта.
		*
		*	@param p тип и параметры заливки обьекта.
		*/
		virtual void setBrush( const QBrush &b );

		/**
		*	Проверяет фигуру на замкнутость.
		*
		*	@return true, если фигура замкнута.
		*/
		virtual bool isClosed() const;

		/**
		*	Устанавливает замкнутость фигуры.
		*
		*	@param closed замкнутость фигуры.
		*/
		virtual void setClosed( bool closed );

		/**
		*	Отрисовывает целиком весь обьект.
		*
		*	@param p то, куда будет производится отрисовка.
		*/
		virtual void paint( QPainter &p );

		/**
		*	Конутсруктор.
		*/
		GContainer();

		/**
		*	Деструктор.
		*/
		virtual ~GContainer();

		/**
		*	Сохраняет весь обьект целиком в поток.
		*
		*	@param stream поток, в который сохраняется обьект.
		*/
		virtual void save( QDataStream &stream ) const;

		/**
		*	Читает весь обьект целиком из потока.
		*
		*	@param stream поток, из которого происходит чтение.
		*/
		virtual void load( QDataStream &stream );

	protected:
		QVector< GObject* > objects;

		int countVisibleObjects() const;

		friend class PaintWidget;
};

/**
*		Пытается преобразовать указатель на любой обьект в указатель на
*	GContainer.
*
*	@param o указатель на некоторый обьект.
*
*	@return преобразованый уазатель, если это возможно, и 0 в противном случае.
*/
template < class T > inline GContainer* GCONTAINER( T *o )
{
	return qobject_cast< GContainer* >( o );
}

#endif /* __GCONTAINER__H__ */
