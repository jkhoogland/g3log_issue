#include <lib/lib.h>

#include <iostream>

#include <g3log/g3log.hpp>
#ifndef LOG_IN_DLL
#include <g3log/logmessage.hpp>
#include <g3log/logworker.hpp>
#endif


int main()
{
#ifndef LOG_IN_DLL
    auto logger = g3::LogWorker::createLogWorker();
    g3::initializeLogging( logger.get() );

    auto pre = "FOO";
    auto dir = ".";
    logger->addDefaultLogger( pre, dir );
#endif

    auto y = foo::doSomething( 2 );
    std::cout << y << std::endl;

    LOG( INFO ) << "blah " << y;

    return 1;
}
