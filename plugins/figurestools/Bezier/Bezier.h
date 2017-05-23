#ifndef __BEZIER_Z__
#define __BEZIER_Z__

#include <QHBoxLayout>
#include <QVBoxLayout>
#include "./../../../pluginTool/Plugin.h"
#include "./../../../pluginTool/InterfacePlugin.h"
#include "./../../../interfaces/ToolBoxInterface.h"
#include "./../../../interfaces/FigureToolInterface.h"

#include <QToolButton>
#include <QWidget>
#include <QObject>
#include "./../../../interfaces/ToolButtonInterface.h"

class ToolButton:public ToolButtonInterface
{
	Q_OBJECT
	Q_INTERFACES( ToolButtonInterface )

	signals:
		void toolSelected( FigureToolInterface *tool );

	public:
		QObject* getTool()
		{
			return tool;
		}

		void setTool(QObject* t)
		{
			tool = FIGURETOOL(t);
		}

		ToolButton( FigureToolInterface *_tool, QWidget *parent ):
			ToolButtonInterface( parent ), tool( _tool )
		{
			setIcon( tool->icon() );
			setToolTip( tool->description() );

			connect( this, SIGNAL( clicked( bool ) ),
					this, SLOT( onClicked( bool ) ) );
		}

		virtual ~ToolButton()
		{
			delete tool;
		}

	private slots:
		void onClicked( bool checked )
		{
			if( !checked ) return;

			tool->toolSelected();
			emit toolSelected( tool );
		}

	private:
		FigureToolInterface *tool;
};

class Z_Bezier:public FigureToolInterface, public InterfacePlugin
{
	Q_OBJECT
	Q_INTERFACES( FigureToolInterface )
	Q_INTERFACES( InterfacePlugin )

	signals:
		void setActive(QString);

	public:

		virtual void createPlugin(QObject *parent, QString idParent,plugin::PluginsManager *manager)
		{
			ToolBoxInterface* tool = TOOLBOX(parent);
			if(tool!=0)
			{
				button = new ToolButton( FIGURETOOL(this), tool);

				QGridLayout* gridLayout= tool->getFigureLayout();
				button->setAutoExclusive( true );
				button->setCheckable( true );
				button->setAutoRaise(true);
				tool->connect( button, SIGNAL( toolSelected( FigureToolInterface* ) ),
						tool, SIGNAL( toolSelected( FigureToolInterface* ) ) );
                gridLayout->addWidget( button, 8, 1, Qt::AlignTop);
			}

			connect( this, SIGNAL( setActive( QString ) ), getBeep(), SIGNAL( setActive( QString ) ) );

			manager->addPlugins(this,"Bezier");
		}

		virtual QWidget* getWidget() {
			return button;
		}

		virtual QString getName()const
		{
			return "Bezier";
		}

		virtual QIcon icon()
		{
            return QIcon( ":/pen/images/bezier.png" );
		}

		virtual CreateStyle createStyle() const
		{
            return paintAfterRelease;
		}

		virtual FiguresInfo figure() const
		{
			FigureInfo info;

			info.closed = false;
            info.spline = true;
            info.points << QPointF( 0.0, 0.0 ) << QPointF( 0.0, 0.0 );
			info.name = figureName();

			return ( FiguresInfo() << info );
		}

		virtual QString description() const
		{
			return tr( "Bezier" );
		}

		virtual QString figureName() const
		{
            return tr( "Bezier line" );
		}

		virtual void toolSelected()
		{
			emit setActive(getName());
		}

		Z_Bezier( plugin::PluginsManager *manager )
		{
			if( !resourcesInited )
			{
                Q_INIT_RESOURCE( Bezier );
				resourcesInited = true;
			}

		}

		virtual ~Z_Bezier()
		{
		}

	private:
		ToolButton *button;
		static bool resourcesInited;
};

#endif /* __BEZIER_Z__ */
