#ifndef DIALOGLAYERSLIST_H
#define DIALOGLAYERSLIST_H

#include <QtGui/QDialog>
#include <QtGui/QStandardItemModel>
#include <QtGui/QListWidgetItem>
#include <QtGui/QListWidget>

#include "ui_ObjectsListWidget.h"
#include "Atlas.h"

class ObjectsListWidget : public QWidget
{
	Q_OBJECT
public:
	ObjectsListWidget( QWidget *parent = 0 );
	~ObjectsListWidget();

private slots:
	void on_layersListWidget_itemClicked( QListWidgetItem* layerItem );
	void on_layersListWidget_currentItemChanged( QListWidgetItem* currentItem, QListWidgetItem* previousItem );
	void on_layersListWidget_itemChanged( QListWidgetItem* layerItem  );

	void ObjectItemChanged( QStandardItem* objectItem );

    void on_uncheckAllLayerButton_clicked();
	void on_checkAllLayerButton_clicked();
	void on_uncheckAllObjectButton_clicked();
	void on_checkAllObjectButton_clicked();
	void on_applyButton_clicked();

	void VisibleMapHasChanged( MapSharedPointer map );

private:
	void SetCheckStateAllLayerItems( Qt::CheckState checkState );
	void SetCheckStateAllObjectItems( QListWidgetItem* const layerItem, Qt::CheckState checkState );
	
    int CalculateCheckObjectItems( const QStandardItemModel* const objectsModel );
	
	void SetCheckStateLayerItemByCheckStateObjectItem( QListWidgetItem* const layerItem, 
													   const int countCheckObjectItems );
	
	void showEvent( QShowEvent* e ); 
	void closeEvent( QCloseEvent* e );
	
	void SetDefaultState();


	void ReadLayers();
	void ReadObjects( QListWidgetItem* const layerItem );

	void ShowLayers();
	void ShowObjects( QListWidgetItem* const layerItem );
	
	void WriteLayers();
	void WriteObjects( QListWidgetItem* const layerItem );

	Ui::ObjectListClass _ui;

	QWeakPointer< Map > _map;
	
	QHash< QListWidgetItem*, QStandardItemModel* > _objectModelsTable;
};

#endif // DIALOGLAYERSLIST_H
