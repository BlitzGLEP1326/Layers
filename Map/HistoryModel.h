#pragma once

#include <QDomDocument>

struct HistoryData
{
	HistoryData()
		: scale( 0 )
		, bright( 0 )
		, contrast( 0 )
		, transparent( 0 )
		, x( 0 )
		, y( 0 )
	{}

	QString path;
	Map::DataType type;
	bool isCurrent;
	bool isVisible;
	qreal scale;
	int bright;
	int contrast;
	int transparent;
	int x;
	int y;
};

class HistoryModel
{
public:
	HistoryModel();
	~HistoryModel();

	QList< HistoryData > GetHistoryDataList();
	void SetHistoryDataList( const QList< HistoryData >& historyDataList );
	
private:
	void CreateTypeTable();
	QString GetFileName() const;
	Map::DataType ConvertStringToDataType( const QString& type ) const;
	
    void CheckDir();
	void ReadHistory();
	void WriteHistory();
    QString GetFilePath();

	QHash< QString, Map::DataType > _typeTable;
	QList< HistoryData > _historyDataList;

    static const QString FileName;
    static const QString DirName;
};
