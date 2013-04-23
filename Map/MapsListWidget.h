#ifndef DATALIST_H
#define DATALIST_H

#include <QDialog>

#include "ui_MapsListWidget.h"
#include "Atlas.h"

class MapsListWidget : public QWidget
{
	Q_OBJECT

public:
	explicit MapsListWidget( Atlas* const atlas, QWidget* parent = 0 );
	~MapsListWidget();

signals:
	void ShowMapsList();

private slots:
	void on_addPushButton_clicked();
	void on_deletePushButton_clicked();
	void on_showPushButton_clicked();
	void on_treeWidget_itemDoubleClicked( QTreeWidgetItem* item, int column );
	
private:
	MapSharedPointer OpenMap( Map::DataType type );
	void CloseMap( const int mapId ) const;
	void SetMapOnScreen( const int mapId ) const;

	QTreeWidgetItem* CreateItem( const int column, QSharedPointer< Map > map ) const;
	void AddItem( QTreeWidgetItem* const parentItem, 
				  QTreeWidgetItem* const item, 
				  Map::DataType type, 
				  const int column );
	void DeleteItem( QTreeWidgetItem* const deleteItem, const int column );
	bool IsTopLevelItem( QTreeWidgetItem* const item ) const;
	
	void SetVisibleMapItem( QTreeWidgetItem* const item, int column );
	bool IsVisibleMapItem( QTreeWidgetItem* const item );

	void SetCurrentItem( QTreeWidgetItem* const item, int column, Map::DataType type );
	void DeleteCurrentItem( QTreeWidgetItem* const deleteItem, int column );
	bool IsCurrentItem( QTreeWidgetItem* const item, const int column ) const;
	
	Ui::DataListClass _ui;
	
	Atlas* const _atlas;
	
	enum{ MapIdRole = Qt::UserRole };

	QHash< Map::DataType, QTreeWidgetItem* > _rootItems;
	QHash< Map::DataType, QString > _filters;
	QHash< Map::DataType, QTreeWidgetItem* > _currentItems;
	QTreeWidgetItem* _visibleMapItem;
};

#endif // DATALIST_H
