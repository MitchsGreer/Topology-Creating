#include <ace/core/core.h>
#if(GUI == 0)
#include <ace/console/eapplication.h>
#else
#include <ace/gui/eapplication.h>
#endif
#include <core/Factories/analytic_factory.h>
#include <core/Factories/data_factory.h>


using namespace std;


int main(int argc, char *argv[])
{
   EApplication application(""
                            ,"KNN"
                            ,0
                            ,0
                            ,9999
                            ,unique_ptr<DataFactory>(new DataFactory)
                            ,unique_ptr<AnalyticFactory>(new AnalyticFactory)
                            ,argc
                            ,argv);
   return application.exec();
}


//to do
// - Finish writing the worker opencl components
//  - to do this i need to read up on oprncl more, dont know how im going to pass all the data up
//    through the buffers
// - Test it with a small GEM file locally
