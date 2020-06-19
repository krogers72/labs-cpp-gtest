#ifndef WEBGADGETPROXY_H
#define WEBGADGETPROXY_H

#include "WebGadget.h"
#include "string.h"

namespace StarTrek {

class WebGadgetProxy
{
public:
    WebGadgetProxy(Untouchables::WebGadget *the_real_gadget) : real_gadget{the_real_gadget} {}

    virtual void writeLine(string message) { real_gadget->writeLine(message); }

    virtual string parameter(string parameterName) { return real_gadget->parameter(parameterName); }

    virtual void* variable(string variableName) { return real_gadget->variable(variableName); }

private:
    Untouchables::WebGadget *real_gadget;

};

}

#endif // WEBGADGETPROXY_H
