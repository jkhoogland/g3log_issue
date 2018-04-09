#include "lib.h"

#include <iostream>

#ifdef LOG_IN_DLL
#include <g3log/g3log.hpp>
#include <g3log/logmessage.hpp>
#include <g3log/logworker.hpp>
#endif

#ifdef LOG_IN_DLL
namespace {
std::once_flag log_init_flag;

std::unique_ptr<g3::LogWorker> logger;

void initLogging()
{
    logger = g3::LogWorker::createLogWorker();
    g3::initializeLogging( logger.get() );

    auto pre = "FOO";
    auto dir = ".";
    logger->addDefaultLogger( pre, dir );
}
}
#endif

namespace foo {

void __attribute__( ( constructor ) ) _init( void )
{
    std::cout << "Loading dll" << std::endl;

#ifdef LOG_IN_DLL
#if 1
    std::call_once( log_init_flag, initLogging );
#else
    // this does not work either
    auto logger = g3::LogWorker::createLogWorker();
    g3::initializeLogging( logger.get() );

    auto pre = "FOO";
    auto dir = ".";
    logger->addDefaultLogger( pre, dir );
#endif
#endif
}


void __attribute__( ( destructor ) ) _final( void )
{
    std::cout << "Unloading dll" << std::endl;
}


int doSomething( int x )
{
    return x * 2;
}
}
