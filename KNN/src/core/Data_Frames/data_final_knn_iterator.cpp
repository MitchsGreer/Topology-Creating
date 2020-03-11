#include "data_final_knn_iterator.h"
//





/*!
*  Creates a new Itereator class object, initializes it with the parent and sets the starting index to 0.
*
*  @param parent The base parent that the iterator will write to
*/
Finalknn::Iterator::Iterator(Finalknn* parent)
{
    EDEBUG_FUNC(this, &parent);
    _index = 0;
    _parent = parent;
}





/*!
*  Writes a row to an output file, each entry  is sepreated by a comma and each row is seperatred by a
*  new line.
*
*  @param input The row to write out onto the file.
*
*  @param index Where in the file it should write the row too.
*
*  @return The byte location in the stream where the writing stopped.
*/
int Finalknn::Iterator::write(QVector<float> dists, QVector<float> indicies, int index)
{
    EDEBUG_FUNC(this, &dists, &indicies, index);
    if(index < 0 || index > _parent->_rowSize)
    {
        E_MAKE_EXCEPTION(e)
        e.setTitle(tr("Seek Error"));
        e.setDetails(tr("Seek encountered an unknown error."));
        throw e;
    }
    if(dists.size() > _parent->_columnSize)
    {
        E_MAKE_EXCEPTION(e)
        e.setTitle(tr("Seek Error"));
        e.setDetails(tr("Seek encountered an unknown error."));
        throw e;
    }
    _parent->seek(sizeof(float) * index * 2 * dists.size() + (3 * sizeof(qint32)) + sizeof(Model*));//using size of the vector as the size of the row.

    for(int i = 0; i < dists.size(); i++)//writes all of the dists first.
    {
        _parent->stream() << dists.at(i);
    }
    for(int i = 0; i < indicies.size(); i++)//writes all of the indicies second.
    {
        _parent->stream() << indicies.at(i);
    }
    return index * indicies.size() + dists.size();
}




/*!
*  Implements an interface to read a row if indicy and distance values from the data
*  object.
*
* @param dists The storage vector for the distance information.
*
* @param indicies The storage vector for the index information.
*
* @param index The which row to read from the data object.
*/
void Finalknn::Iterator::read(QVector<float> &dists, QVector<float> &indicies, int index)
{
    EDEBUG_FUNC(this, &dists, &indicies, index);
    if(index < 0 || index > _parent->_rowSize)
    {
        E_MAKE_EXCEPTION(e)
        e.setTitle(tr("Seek Error"));
        e.setDetails(tr("Seek encountered an unknown error."));
        throw e;
    }

    //getting us to the right location, the row info + the header info
    qint64 pos =sizeof(float) * index * 2 * _parent->_columnSize + sizeof(_parent->_columnSize) + sizeof(_parent->_rowSize) + sizeof(_parent->_k)+ sizeof(Model*);
    _parent->seek(pos);

    //read the dist data first
    for (int i = 0; i < _parent->_k; i++)
    {
        _parent->stream() >> dists[i];
    }
    //read the indicies data
    for (int i = 0; i < _parent->_k; i++)
    {
        _parent->stream() >> indicies[i];
    }

    //go back to the beggining
    _parent->seek(0);
}
