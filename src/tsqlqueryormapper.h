#ifndef TSQLQUERYORMAPPER_H
#define TSQLQUERYORMAPPER_H

#include <QtSql>
#include <QList>
#include <TSqlQuery>
#include <TCriteriaConverter>
#include <TSystemGlobal>


template <class T>
class TSqlQueryORMapper : public TSqlQuery
{
public:
    TSqlQueryORMapper(int databaseId = 0);

    TSqlQueryORMapper<T> &prepare(const QString &query);
    bool load(const QString &filename);
    TSqlQueryORMapper<T> &bind(const QString &placeholder, const QVariant &val);
    TSqlQueryORMapper<T> &bind(int pos, const QVariant &val);
    TSqlQueryORMapper<T> &addBind(const QVariant &val);
    bool exec(const QString &query);
    bool exec();
    T execFirst(const QString &query);
    T execFirst();
    int numRowsAffected() const;
    int size() const;
    bool next();
    T value() const;
    QString fieldName(int index) const;
};


template <class T>
inline TSqlQueryORMapper<T>::TSqlQueryORMapper(int databaseId)
    : TSqlQuery(databaseId)
{ }


template <class T>
inline TSqlQueryORMapper<T> &TSqlQueryORMapper<T>::prepare(const QString &query)
{
    TSqlQuery::prepare(query);
    return *this;
}


template <class T>
inline bool TSqlQueryORMapper<T>::load(const QString &filename)
{
    return TSqlQuery::load(filename);
}


template <class T>
inline TSqlQueryORMapper<T> &TSqlQueryORMapper<T>::bind(const QString &placeholder, const QVariant &val)
{
    TSqlQuery::bind(placeholder, val);
    return *this;
}


template <class T>
inline TSqlQueryORMapper<T> &TSqlQueryORMapper<T>::bind(int pos, const QVariant &val)
{
    TSqlQuery::bind(pos, val);
    return *this;
}


template <class T>
inline TSqlQueryORMapper<T> &TSqlQueryORMapper<T>::addBind(const QVariant &val)
{
    TSqlQuery::addBind(val);
    return *this;
}


template <class T>
inline bool TSqlQueryORMapper<T>::exec(const QString &query)
{
    return TSqlQuery::exec(query);
}


template <class T>
inline bool TSqlQueryORMapper<T>::exec()
{
    return TSqlQuery::exec();
}


template <class T>
inline T TSqlQueryORMapper<T>::execFirst(const QString &query)
{
    exec(query);
    return (next()) ? value() : T();
}


template <class T>
inline T TSqlQueryORMapper<T>::execFirst()
{
    exec();
    return (next()) ? value() : T();
}

// template <class T>
// inline QList<T> TSqlQueryORMapper<T>::findAll()
// {
//     exec();
//     QList<T> list;
//     while (next()) {
//         list.append(value());
//     }
//     return list;
// }

template <class T>
inline int TSqlQueryORMapper<T>::numRowsAffected() const
{
    return TSqlQuery::numRowsAffected();
}


template <class T>
inline int TSqlQueryORMapper<T>::size() const
{
    return TSqlQuery::size();
}


template <class T>
inline bool TSqlQueryORMapper<T>::next()
{
    return TSqlQuery::next();
}


template <class T>
inline T TSqlQueryORMapper<T>::value() const
{
    T rec;
    QSqlRecord r = record();
    rec.setRecord(r, lastError());
    return rec;
}


template <class T>
inline QString TSqlQueryORMapper<T>::fieldName(int index) const
{
    return TCriteriaConverter<T>::propertyName(index);
}

#endif // TSQLQUERYORMAPPER_H
