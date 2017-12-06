#include <asiodnp3/DNP3Manager.h>
#include <asiodnp3/PrintingSOEHandler.h>
#include <asiodnp3/PrintingChannelListener.h>
#include <asiodnp3/ConsoleLogger.h>
#include <UpdateBuilder.h>

#include <asiopal/UTCTimeSource.h>
#include opendnp3/outstation/SimpleCommandHandler.h>

#include <opendnp3/outstation/IUpdateHandler.h>

#include <opendnp3/LogLevels.h>

#include <string>
#include <thread>
#include <iostream>

using namespace std;
using namespace opendnp3;
using namespace openpal;
using namespace asiopal;
using namespace asiodnp3;


int main(int argc, char *argv[])
{

/************************************************************************************************/
        OutstationStackConfig stackConfig;
/************************************************************************************************/

        //Database stuff
        stackConfig.dbTemplate = DatabaseTemplate::AllTypes(10);
        stackConfig.outstation.eventBufferConfig = EventBufferConfig::AllTypes(10);

        //Overridden stuff
        stackConfig.outstation.params.allowUnsolicited = true;

        //Changed the default link Addresses
        stackConfig.link.LocalAddr = 10;
        stackConfig.link.RemoteAddr = 1;

        auto outstation = channel->AddOutstation(
                "outstation",                                   //logging alias
                SuccessCommandHandler::Create(),                //ICommandHandler (interface)
                DefaultOutstationApplication::Create(),         //IOutstationApplication (interface)
                stackConfig                                     //static stack configuration
        );

        outstation->Enable();


        while(true)
        {
                UpdateBuilder builder;
                builder.Update(Binary(state.binary), 0);
                builder.Update(Binary(state.binary), 1);
                builder.Update(Binary(state.binary), 2);
                builder.Update(Binary(state.binary), 3);
                builder.Update(Binary(state.binary), 4);
                
                
                //builder.Update(Analog(state.value), 0);
                
                
