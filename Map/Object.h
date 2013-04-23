#pragma once

class Object
{
public:
	Object( QSharedPointer< const Data > data, const int numberLayer, const int numberObject );
	~Object();
	
	QString GetName() const;
	int GetNumber() const;
	bool IsVisible() const;

	void Enable(  const GisToolWrapper::SelectContextId selectContextId, const int numberLayer );
	void Disable(  const GisToolWrapper::SelectContextId selectContextId, const int numberLayer );

private:
	void SetAccessObject( const GisToolWrapper::SelectContextId selectContextId, const int numberLayer ) const;

	QSharedPointer< const Data > _data;
	QString _name;
	int _number;
	bool _visible;
};
