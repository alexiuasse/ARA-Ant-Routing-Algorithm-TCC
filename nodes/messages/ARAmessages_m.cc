//
// Generated file, do not edit! Created by nedtool 4.6 from nodes/messages/ARAmessages.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "ARAmessages_m.h"

USING_NAMESPACE


// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




// Template rule for outputting std::vector<T> types
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

Register_Class(RETRY);

RETRY::RETRY(const char *name, int kind) : ::cPacket(name,kind)
{
    this->flag_var = 0;
}

RETRY::RETRY(const RETRY& other) : ::cPacket(other)
{
    copy(other);
}

RETRY::~RETRY()
{
}

RETRY& RETRY::operator=(const RETRY& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void RETRY::copy(const RETRY& other)
{
    this->flag_var = other.flag_var;
}

void RETRY::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->flag_var);
}

void RETRY::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->flag_var);
}

bool RETRY::getFlag() const
{
    return flag_var;
}

void RETRY::setFlag(bool flag)
{
    this->flag_var = flag;
}

class RETRYDescriptor : public cClassDescriptor
{
  public:
    RETRYDescriptor();
    virtual ~RETRYDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(RETRYDescriptor);

RETRYDescriptor::RETRYDescriptor() : cClassDescriptor("RETRY", "cPacket")
{
}

RETRYDescriptor::~RETRYDescriptor()
{
}

bool RETRYDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<RETRY *>(obj)!=NULL;
}

const char *RETRYDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int RETRYDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int RETRYDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *RETRYDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "flag",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int RETRYDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='f' && strcmp(fieldName, "flag")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *RETRYDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "bool",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *RETRYDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int RETRYDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    RETRY *pp = (RETRY *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string RETRYDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    RETRY *pp = (RETRY *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getFlag());
        default: return "";
    }
}

bool RETRYDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    RETRY *pp = (RETRY *)object; (void)pp;
    switch (field) {
        case 0: pp->setFlag(string2bool(value)); return true;
        default: return false;
    }
}

const char *RETRYDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *RETRYDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    RETRY *pp = (RETRY *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(ROUTE_ERROR);

ROUTE_ERROR::ROUTE_ERROR(const char *name, int kind) : ::cPacket(name,kind)
{
    this->my_addr_var = 0;
    this->dest_addr_var = 0;
}

ROUTE_ERROR::ROUTE_ERROR(const ROUTE_ERROR& other) : ::cPacket(other)
{
    copy(other);
}

ROUTE_ERROR::~ROUTE_ERROR()
{
}

ROUTE_ERROR& ROUTE_ERROR::operator=(const ROUTE_ERROR& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void ROUTE_ERROR::copy(const ROUTE_ERROR& other)
{
    this->my_addr_var = other.my_addr_var;
    this->dest_addr_var = other.dest_addr_var;
}

void ROUTE_ERROR::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->my_addr_var);
    doPacking(b,this->dest_addr_var);
}

void ROUTE_ERROR::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->my_addr_var);
    doUnpacking(b,this->dest_addr_var);
}

int ROUTE_ERROR::getMy_addr() const
{
    return my_addr_var;
}

void ROUTE_ERROR::setMy_addr(int my_addr)
{
    this->my_addr_var = my_addr;
}

int ROUTE_ERROR::getDest_addr() const
{
    return dest_addr_var;
}

void ROUTE_ERROR::setDest_addr(int dest_addr)
{
    this->dest_addr_var = dest_addr;
}

class ROUTE_ERRORDescriptor : public cClassDescriptor
{
  public:
    ROUTE_ERRORDescriptor();
    virtual ~ROUTE_ERRORDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(ROUTE_ERRORDescriptor);

ROUTE_ERRORDescriptor::ROUTE_ERRORDescriptor() : cClassDescriptor("ROUTE_ERROR", "cPacket")
{
}

ROUTE_ERRORDescriptor::~ROUTE_ERRORDescriptor()
{
}

bool ROUTE_ERRORDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<ROUTE_ERROR *>(obj)!=NULL;
}

const char *ROUTE_ERRORDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int ROUTE_ERRORDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int ROUTE_ERRORDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *ROUTE_ERRORDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "my_addr",
        "dest_addr",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int ROUTE_ERRORDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "my_addr")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "dest_addr")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *ROUTE_ERRORDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *ROUTE_ERRORDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int ROUTE_ERRORDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    ROUTE_ERROR *pp = (ROUTE_ERROR *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string ROUTE_ERRORDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    ROUTE_ERROR *pp = (ROUTE_ERROR *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getMy_addr());
        case 1: return long2string(pp->getDest_addr());
        default: return "";
    }
}

bool ROUTE_ERRORDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    ROUTE_ERROR *pp = (ROUTE_ERROR *)object; (void)pp;
    switch (field) {
        case 0: pp->setMy_addr(string2long(value)); return true;
        case 1: pp->setDest_addr(string2long(value)); return true;
        default: return false;
    }
}

const char *ROUTE_ERRORDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *ROUTE_ERRORDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    ROUTE_ERROR *pp = (ROUTE_ERROR *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(FANT);

FANT::FANT(const char *name, int kind) : ::cPacket(name,kind)
{
    this->id_var = 0;
    this->pheromone_value_var = 0;
    this->hops_var = 0;
    this->dest_addr_var = 0;
    this->previous_addr_var = 0;
    this->source_addr_var = 0;
}

FANT::FANT(const FANT& other) : ::cPacket(other)
{
    copy(other);
}

FANT::~FANT()
{
}

FANT& FANT::operator=(const FANT& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void FANT::copy(const FANT& other)
{
    this->id_var = other.id_var;
    this->pheromone_value_var = other.pheromone_value_var;
    this->hops_var = other.hops_var;
    this->dest_addr_var = other.dest_addr_var;
    this->previous_addr_var = other.previous_addr_var;
    this->source_addr_var = other.source_addr_var;
}

void FANT::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->id_var);
    doPacking(b,this->pheromone_value_var);
    doPacking(b,this->hops_var);
    doPacking(b,this->dest_addr_var);
    doPacking(b,this->previous_addr_var);
    doPacking(b,this->source_addr_var);
}

void FANT::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->id_var);
    doUnpacking(b,this->pheromone_value_var);
    doUnpacking(b,this->hops_var);
    doUnpacking(b,this->dest_addr_var);
    doUnpacking(b,this->previous_addr_var);
    doUnpacking(b,this->source_addr_var);
}

int FANT::getId() const
{
    return id_var;
}

void FANT::setId(int id)
{
    this->id_var = id;
}

double FANT::getPheromone_value() const
{
    return pheromone_value_var;
}

void FANT::setPheromone_value(double pheromone_value)
{
    this->pheromone_value_var = pheromone_value;
}

double FANT::getHops() const
{
    return hops_var;
}

void FANT::setHops(double hops)
{
    this->hops_var = hops;
}

int FANT::getDest_addr() const
{
    return dest_addr_var;
}

void FANT::setDest_addr(int dest_addr)
{
    this->dest_addr_var = dest_addr;
}

int FANT::getPrevious_addr() const
{
    return previous_addr_var;
}

void FANT::setPrevious_addr(int previous_addr)
{
    this->previous_addr_var = previous_addr;
}

int FANT::getSource_addr() const
{
    return source_addr_var;
}

void FANT::setSource_addr(int source_addr)
{
    this->source_addr_var = source_addr;
}

class FANTDescriptor : public cClassDescriptor
{
  public:
    FANTDescriptor();
    virtual ~FANTDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(FANTDescriptor);

FANTDescriptor::FANTDescriptor() : cClassDescriptor("FANT", "cPacket")
{
}

FANTDescriptor::~FANTDescriptor()
{
}

bool FANTDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<FANT *>(obj)!=NULL;
}

const char *FANTDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int FANTDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount(object) : 6;
}

unsigned int FANTDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *FANTDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "id",
        "pheromone_value",
        "hops",
        "dest_addr",
        "previous_addr",
        "source_addr",
    };
    return (field>=0 && field<6) ? fieldNames[field] : NULL;
}

int FANTDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "id")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "pheromone_value")==0) return base+1;
    if (fieldName[0]=='h' && strcmp(fieldName, "hops")==0) return base+2;
    if (fieldName[0]=='d' && strcmp(fieldName, "dest_addr")==0) return base+3;
    if (fieldName[0]=='p' && strcmp(fieldName, "previous_addr")==0) return base+4;
    if (fieldName[0]=='s' && strcmp(fieldName, "source_addr")==0) return base+5;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *FANTDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "double",
        "double",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : NULL;
}

const char *FANTDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int FANTDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    FANT *pp = (FANT *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string FANTDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    FANT *pp = (FANT *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getId());
        case 1: return double2string(pp->getPheromone_value());
        case 2: return double2string(pp->getHops());
        case 3: return long2string(pp->getDest_addr());
        case 4: return long2string(pp->getPrevious_addr());
        case 5: return long2string(pp->getSource_addr());
        default: return "";
    }
}

bool FANTDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    FANT *pp = (FANT *)object; (void)pp;
    switch (field) {
        case 0: pp->setId(string2long(value)); return true;
        case 1: pp->setPheromone_value(string2double(value)); return true;
        case 2: pp->setHops(string2double(value)); return true;
        case 3: pp->setDest_addr(string2long(value)); return true;
        case 4: pp->setPrevious_addr(string2long(value)); return true;
        case 5: pp->setSource_addr(string2long(value)); return true;
        default: return false;
    }
}

const char *FANTDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *FANTDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    FANT *pp = (FANT *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(BANT);

BANT::BANT(const char *name, int kind) : ::cPacket(name,kind)
{
    this->pheromone_value_var = 0;
    this->hops_var = 0;
    this->id_var = 0;
    this->dest_addr_var = 0;
    this->next_addr_var = 0;
    this->source_addr_var = 0;
    this->previous_addr_var = 0;
}

BANT::BANT(const BANT& other) : ::cPacket(other)
{
    copy(other);
}

BANT::~BANT()
{
}

BANT& BANT::operator=(const BANT& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void BANT::copy(const BANT& other)
{
    this->pheromone_value_var = other.pheromone_value_var;
    this->hops_var = other.hops_var;
    this->id_var = other.id_var;
    this->dest_addr_var = other.dest_addr_var;
    this->next_addr_var = other.next_addr_var;
    this->source_addr_var = other.source_addr_var;
    this->previous_addr_var = other.previous_addr_var;
}

void BANT::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->pheromone_value_var);
    doPacking(b,this->hops_var);
    doPacking(b,this->id_var);
    doPacking(b,this->dest_addr_var);
    doPacking(b,this->next_addr_var);
    doPacking(b,this->source_addr_var);
    doPacking(b,this->previous_addr_var);
}

void BANT::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->pheromone_value_var);
    doUnpacking(b,this->hops_var);
    doUnpacking(b,this->id_var);
    doUnpacking(b,this->dest_addr_var);
    doUnpacking(b,this->next_addr_var);
    doUnpacking(b,this->source_addr_var);
    doUnpacking(b,this->previous_addr_var);
}

double BANT::getPheromone_value() const
{
    return pheromone_value_var;
}

void BANT::setPheromone_value(double pheromone_value)
{
    this->pheromone_value_var = pheromone_value;
}

double BANT::getHops() const
{
    return hops_var;
}

void BANT::setHops(double hops)
{
    this->hops_var = hops;
}

int BANT::getId() const
{
    return id_var;
}

void BANT::setId(int id)
{
    this->id_var = id;
}

int BANT::getDest_addr() const
{
    return dest_addr_var;
}

void BANT::setDest_addr(int dest_addr)
{
    this->dest_addr_var = dest_addr;
}

int BANT::getNext_addr() const
{
    return next_addr_var;
}

void BANT::setNext_addr(int next_addr)
{
    this->next_addr_var = next_addr;
}

int BANT::getSource_addr() const
{
    return source_addr_var;
}

void BANT::setSource_addr(int source_addr)
{
    this->source_addr_var = source_addr;
}

int BANT::getPrevious_addr() const
{
    return previous_addr_var;
}

void BANT::setPrevious_addr(int previous_addr)
{
    this->previous_addr_var = previous_addr;
}

class BANTDescriptor : public cClassDescriptor
{
  public:
    BANTDescriptor();
    virtual ~BANTDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(BANTDescriptor);

BANTDescriptor::BANTDescriptor() : cClassDescriptor("BANT", "cPacket")
{
}

BANTDescriptor::~BANTDescriptor()
{
}

bool BANTDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<BANT *>(obj)!=NULL;
}

const char *BANTDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int BANTDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount(object) : 7;
}

unsigned int BANTDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *BANTDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "pheromone_value",
        "hops",
        "id",
        "dest_addr",
        "next_addr",
        "source_addr",
        "previous_addr",
    };
    return (field>=0 && field<7) ? fieldNames[field] : NULL;
}

int BANTDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "pheromone_value")==0) return base+0;
    if (fieldName[0]=='h' && strcmp(fieldName, "hops")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "id")==0) return base+2;
    if (fieldName[0]=='d' && strcmp(fieldName, "dest_addr")==0) return base+3;
    if (fieldName[0]=='n' && strcmp(fieldName, "next_addr")==0) return base+4;
    if (fieldName[0]=='s' && strcmp(fieldName, "source_addr")==0) return base+5;
    if (fieldName[0]=='p' && strcmp(fieldName, "previous_addr")==0) return base+6;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *BANTDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "double",
        "double",
        "int",
        "int",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : NULL;
}

const char *BANTDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int BANTDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    BANT *pp = (BANT *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string BANTDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    BANT *pp = (BANT *)object; (void)pp;
    switch (field) {
        case 0: return double2string(pp->getPheromone_value());
        case 1: return double2string(pp->getHops());
        case 2: return long2string(pp->getId());
        case 3: return long2string(pp->getDest_addr());
        case 4: return long2string(pp->getNext_addr());
        case 5: return long2string(pp->getSource_addr());
        case 6: return long2string(pp->getPrevious_addr());
        default: return "";
    }
}

bool BANTDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    BANT *pp = (BANT *)object; (void)pp;
    switch (field) {
        case 0: pp->setPheromone_value(string2double(value)); return true;
        case 1: pp->setHops(string2double(value)); return true;
        case 2: pp->setId(string2long(value)); return true;
        case 3: pp->setDest_addr(string2long(value)); return true;
        case 4: pp->setNext_addr(string2long(value)); return true;
        case 5: pp->setSource_addr(string2long(value)); return true;
        case 6: pp->setPrevious_addr(string2long(value)); return true;
        default: return false;
    }
}

const char *BANTDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *BANTDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    BANT *pp = (BANT *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(DATA);

DATA::DATA(const char *name, int kind) : ::cPacket(name,kind)
{
    this->data_var = 0;
    this->pheromone_value_var = 0;
    this->hops_var = 0;
    this->id_var = 0;
    this->TTL_var = 0;
    this->forward_var = 0;
    this->ERROR_var = 0;
    this->my_addr_var = 0;
    this->dest_addr_var = 0;
    this->next_addr_var = 0;
    this->source_addr_var = 0;
}

DATA::DATA(const DATA& other) : ::cPacket(other)
{
    copy(other);
}

DATA::~DATA()
{
}

DATA& DATA::operator=(const DATA& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void DATA::copy(const DATA& other)
{
    this->data_var = other.data_var;
    this->pheromone_value_var = other.pheromone_value_var;
    this->hops_var = other.hops_var;
    this->id_var = other.id_var;
    this->TTL_var = other.TTL_var;
    this->forward_var = other.forward_var;
    this->ERROR_var = other.ERROR_var;
    this->my_addr_var = other.my_addr_var;
    this->dest_addr_var = other.dest_addr_var;
    this->next_addr_var = other.next_addr_var;
    this->source_addr_var = other.source_addr_var;
}

void DATA::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->data_var);
    doPacking(b,this->pheromone_value_var);
    doPacking(b,this->hops_var);
    doPacking(b,this->id_var);
    doPacking(b,this->TTL_var);
    doPacking(b,this->forward_var);
    doPacking(b,this->ERROR_var);
    doPacking(b,this->my_addr_var);
    doPacking(b,this->dest_addr_var);
    doPacking(b,this->next_addr_var);
    doPacking(b,this->source_addr_var);
}

void DATA::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->data_var);
    doUnpacking(b,this->pheromone_value_var);
    doUnpacking(b,this->hops_var);
    doUnpacking(b,this->id_var);
    doUnpacking(b,this->TTL_var);
    doUnpacking(b,this->forward_var);
    doUnpacking(b,this->ERROR_var);
    doUnpacking(b,this->my_addr_var);
    doUnpacking(b,this->dest_addr_var);
    doUnpacking(b,this->next_addr_var);
    doUnpacking(b,this->source_addr_var);
}

int DATA::getData() const
{
    return data_var;
}

void DATA::setData(int data)
{
    this->data_var = data;
}

double DATA::getPheromone_value() const
{
    return pheromone_value_var;
}

void DATA::setPheromone_value(double pheromone_value)
{
    this->pheromone_value_var = pheromone_value;
}

double DATA::getHops() const
{
    return hops_var;
}

void DATA::setHops(double hops)
{
    this->hops_var = hops;
}

int DATA::getId() const
{
    return id_var;
}

void DATA::setId(int id)
{
    this->id_var = id;
}

int DATA::getTTL() const
{
    return TTL_var;
}

void DATA::setTTL(int TTL)
{
    this->TTL_var = TTL;
}

bool DATA::getForward() const
{
    return forward_var;
}

void DATA::setForward(bool forward)
{
    this->forward_var = forward;
}

bool DATA::getERROR() const
{
    return ERROR_var;
}

void DATA::setERROR(bool ERROR)
{
    this->ERROR_var = ERROR;
}

int DATA::getMy_addr() const
{
    return my_addr_var;
}

void DATA::setMy_addr(int my_addr)
{
    this->my_addr_var = my_addr;
}

int DATA::getDest_addr() const
{
    return dest_addr_var;
}

void DATA::setDest_addr(int dest_addr)
{
    this->dest_addr_var = dest_addr;
}

int DATA::getNext_addr() const
{
    return next_addr_var;
}

void DATA::setNext_addr(int next_addr)
{
    this->next_addr_var = next_addr;
}

int DATA::getSource_addr() const
{
    return source_addr_var;
}

void DATA::setSource_addr(int source_addr)
{
    this->source_addr_var = source_addr;
}

class DATADescriptor : public cClassDescriptor
{
  public:
    DATADescriptor();
    virtual ~DATADescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(DATADescriptor);

DATADescriptor::DATADescriptor() : cClassDescriptor("DATA", "cPacket")
{
}

DATADescriptor::~DATADescriptor()
{
}

bool DATADescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<DATA *>(obj)!=NULL;
}

const char *DATADescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int DATADescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 11+basedesc->getFieldCount(object) : 11;
}

unsigned int DATADescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<11) ? fieldTypeFlags[field] : 0;
}

const char *DATADescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "data",
        "pheromone_value",
        "hops",
        "id",
        "TTL",
        "forward",
        "ERROR",
        "my_addr",
        "dest_addr",
        "next_addr",
        "source_addr",
    };
    return (field>=0 && field<11) ? fieldNames[field] : NULL;
}

int DATADescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='d' && strcmp(fieldName, "data")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "pheromone_value")==0) return base+1;
    if (fieldName[0]=='h' && strcmp(fieldName, "hops")==0) return base+2;
    if (fieldName[0]=='i' && strcmp(fieldName, "id")==0) return base+3;
    if (fieldName[0]=='T' && strcmp(fieldName, "TTL")==0) return base+4;
    if (fieldName[0]=='f' && strcmp(fieldName, "forward")==0) return base+5;
    if (fieldName[0]=='E' && strcmp(fieldName, "ERROR")==0) return base+6;
    if (fieldName[0]=='m' && strcmp(fieldName, "my_addr")==0) return base+7;
    if (fieldName[0]=='d' && strcmp(fieldName, "dest_addr")==0) return base+8;
    if (fieldName[0]=='n' && strcmp(fieldName, "next_addr")==0) return base+9;
    if (fieldName[0]=='s' && strcmp(fieldName, "source_addr")==0) return base+10;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *DATADescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "double",
        "double",
        "int",
        "int",
        "bool",
        "bool",
        "int",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<11) ? fieldTypeStrings[field] : NULL;
}

const char *DATADescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int DATADescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    DATA *pp = (DATA *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string DATADescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    DATA *pp = (DATA *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getData());
        case 1: return double2string(pp->getPheromone_value());
        case 2: return double2string(pp->getHops());
        case 3: return long2string(pp->getId());
        case 4: return long2string(pp->getTTL());
        case 5: return bool2string(pp->getForward());
        case 6: return bool2string(pp->getERROR());
        case 7: return long2string(pp->getMy_addr());
        case 8: return long2string(pp->getDest_addr());
        case 9: return long2string(pp->getNext_addr());
        case 10: return long2string(pp->getSource_addr());
        default: return "";
    }
}

bool DATADescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    DATA *pp = (DATA *)object; (void)pp;
    switch (field) {
        case 0: pp->setData(string2long(value)); return true;
        case 1: pp->setPheromone_value(string2double(value)); return true;
        case 2: pp->setHops(string2double(value)); return true;
        case 3: pp->setId(string2long(value)); return true;
        case 4: pp->setTTL(string2long(value)); return true;
        case 5: pp->setForward(string2bool(value)); return true;
        case 6: pp->setERROR(string2bool(value)); return true;
        case 7: pp->setMy_addr(string2long(value)); return true;
        case 8: pp->setDest_addr(string2long(value)); return true;
        case 9: pp->setNext_addr(string2long(value)); return true;
        case 10: pp->setSource_addr(string2long(value)); return true;
        default: return false;
    }
}

const char *DATADescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *DATADescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    DATA *pp = (DATA *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


