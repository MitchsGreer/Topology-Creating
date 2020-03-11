#include "export_final_knn.h"
#include "export_final_knn_input.h"
#include "../Data_Frames/data_final_knn_iterator.h"
//





/*!
 * Implements the interface that Returns the number of times ACE will break up the work load.
 *
 * @return The integer representation of the size, in this case we are breaking it up by the row.
 */
int ExportFinalknn::size() const
{
    EDEBUG_FUNC(this);
    return _in->_rowSize / 2;
}






/*!
 * Implements the interface that processes the work blocks
 *
 * @return The integer representation of the size, in this case on block for each row.
 */
void ExportFinalknn::process(const EAbstractAnalyticBlock* result)
{
    EDEBUG_FUNC(this, &result);
    //for all of the rows we can just write the data in the Finalknn
    //We dont need to worry about row or column names, because this is an intermediate step.
    if((uint)result->index() <= _rows) //i dont remember if it starts indexing at 0 or not
    {

        if(result->index() == 0)
        {
            _indiciesStream.setDevice(_indiciesOut);
            _distsStream.setDevice(_distsOut);
        }


        _rows = _in->_rowSize;
        _columns = _in->_k;

        QVector<float> dists;
        QVector<float> indicies;

        dists.resize(_in->_k);
        indicies.resize(_in->_k);

        Finalknn::Iterator it(_in);

        it.read(dists, indicies, result->index());
        //write it to the file
        for(int i = 0; i < indicies.size(); i++)
        {

            //the value might be a nan or a double, we need to check for that.
            if(indicies.at(i) == NAN)
            {
                _indiciesStream << "NA";
            }
            //its a regular value.
            else
            {
                _indiciesStream << indicies.at(i);
            }
            //print a tab after each one.
            _indiciesStream << "\t";
        }
        _indiciesStream << "\n";

        //write it to the file
        for(int i = 0; i < dists.size(); i++)
        {
            //the value might be a nan or a double, we need to check for that.
            if(dists.at(i) == NAN)
            {
                _distsStream << "NA";
            }
            else
            {
                _distsStream << dists.at(i);
            }
            _distsStream << "\t";
        }
        _distsStream << "\n";
    }

    // make sure writing output file worked
    if ( _indiciesStream.status() != QTextStream::Ok && _distsStream.status() != QTextStream::Ok)
    {
       E_MAKE_EXCEPTION(e);
       e.setTitle(tr("File IO Error"));
       e.setDetails(tr("Qt Text Stream encountered an unknown error."));
       throw e;
    }
}






EAbstractAnalyticInput* ExportFinalknn::makeInput()
{
    EDEBUG_FUNC(this);
    return new Input(this);
}






void ExportFinalknn::initializeOutputs()
{
    EDEBUG_FUNC(this);
    if ( !_distsOut || !_indiciesOut )
    {
      E_MAKE_EXCEPTION(e);
      e.setTitle(tr("Invalid Argument"));
      e.setDetails(tr("The required output files were not set."));
     throw e;
    }
}
