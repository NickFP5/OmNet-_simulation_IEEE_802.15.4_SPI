//
// Generated file, do not edit! Created by nedtool 4.6 from SpiPrimitive.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "SpiPrimitive_m.h"

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

Register_Class(setTxModePrimitive);

setTxModePrimitive::setTxModePrimitive(const char *name, int kind) : ::cPacket(name,kind)
{
    this->channel_var = 0;
    this->genTime_var = 0;
}

setTxModePrimitive::setTxModePrimitive(const setTxModePrimitive& other) : ::cPacket(other)
{
    copy(other);
}

setTxModePrimitive::~setTxModePrimitive()
{
}

setTxModePrimitive& setTxModePrimitive::operator=(const setTxModePrimitive& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void setTxModePrimitive::copy(const setTxModePrimitive& other)
{
    this->channel_var = other.channel_var;
    this->genTime_var = other.genTime_var;
}

void setTxModePrimitive::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->channel_var);
    doPacking(b,this->genTime_var);
}

void setTxModePrimitive::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->channel_var);
    doUnpacking(b,this->genTime_var);
}

int setTxModePrimitive::getChannel() const
{
    return channel_var;
}

void setTxModePrimitive::setChannel(int channel)
{
    this->channel_var = channel;
}

double setTxModePrimitive::getGenTime() const
{
    return genTime_var;
}

void setTxModePrimitive::setGenTime(double genTime)
{
    this->genTime_var = genTime;
}

class setTxModePrimitiveDescriptor : public cClassDescriptor
{
  public:
    setTxModePrimitiveDescriptor();
    virtual ~setTxModePrimitiveDescriptor();

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

Register_ClassDescriptor(setTxModePrimitiveDescriptor);

setTxModePrimitiveDescriptor::setTxModePrimitiveDescriptor() : cClassDescriptor("setTxModePrimitive", "cPacket")
{
}

setTxModePrimitiveDescriptor::~setTxModePrimitiveDescriptor()
{
}

bool setTxModePrimitiveDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<setTxModePrimitive *>(obj)!=NULL;
}

const char *setTxModePrimitiveDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int setTxModePrimitiveDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int setTxModePrimitiveDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *setTxModePrimitiveDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "channel",
        "genTime",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int setTxModePrimitiveDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "channel")==0) return base+0;
    if (fieldName[0]=='g' && strcmp(fieldName, "genTime")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *setTxModePrimitiveDescriptor::getFieldTypeString(void *object, int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *setTxModePrimitiveDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int setTxModePrimitiveDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    setTxModePrimitive *pp = (setTxModePrimitive *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string setTxModePrimitiveDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    setTxModePrimitive *pp = (setTxModePrimitive *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getChannel());
        case 1: return double2string(pp->getGenTime());
        default: return "";
    }
}

bool setTxModePrimitiveDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    setTxModePrimitive *pp = (setTxModePrimitive *)object; (void)pp;
    switch (field) {
        case 0: pp->setChannel(string2long(value)); return true;
        case 1: pp->setGenTime(string2double(value)); return true;
        default: return false;
    }
}

const char *setTxModePrimitiveDescriptor::getFieldStructName(void *object, int field) const
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

void *setTxModePrimitiveDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    setTxModePrimitive *pp = (setTxModePrimitive *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(confirmSetTxModePrimitive);

confirmSetTxModePrimitive::confirmSetTxModePrimitive(const char *name, int kind) : ::cPacket(name,kind)
{
}

confirmSetTxModePrimitive::confirmSetTxModePrimitive(const confirmSetTxModePrimitive& other) : ::cPacket(other)
{
    copy(other);
}

confirmSetTxModePrimitive::~confirmSetTxModePrimitive()
{
}

confirmSetTxModePrimitive& confirmSetTxModePrimitive::operator=(const confirmSetTxModePrimitive& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void confirmSetTxModePrimitive::copy(const confirmSetTxModePrimitive& other)
{
}

void confirmSetTxModePrimitive::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
}

void confirmSetTxModePrimitive::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
}

class confirmSetTxModePrimitiveDescriptor : public cClassDescriptor
{
  public:
    confirmSetTxModePrimitiveDescriptor();
    virtual ~confirmSetTxModePrimitiveDescriptor();

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

Register_ClassDescriptor(confirmSetTxModePrimitiveDescriptor);

confirmSetTxModePrimitiveDescriptor::confirmSetTxModePrimitiveDescriptor() : cClassDescriptor("confirmSetTxModePrimitive", "cPacket")
{
}

confirmSetTxModePrimitiveDescriptor::~confirmSetTxModePrimitiveDescriptor()
{
}

bool confirmSetTxModePrimitiveDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<confirmSetTxModePrimitive *>(obj)!=NULL;
}

const char *confirmSetTxModePrimitiveDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int confirmSetTxModePrimitiveDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int confirmSetTxModePrimitiveDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *confirmSetTxModePrimitiveDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int confirmSetTxModePrimitiveDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *confirmSetTxModePrimitiveDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *confirmSetTxModePrimitiveDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int confirmSetTxModePrimitiveDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    confirmSetTxModePrimitive *pp = (confirmSetTxModePrimitive *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string confirmSetTxModePrimitiveDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    confirmSetTxModePrimitive *pp = (confirmSetTxModePrimitive *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool confirmSetTxModePrimitiveDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    confirmSetTxModePrimitive *pp = (confirmSetTxModePrimitive *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *confirmSetTxModePrimitiveDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *confirmSetTxModePrimitiveDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    confirmSetTxModePrimitive *pp = (confirmSetTxModePrimitive *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(TxDonePrimitive);

TxDonePrimitive::TxDonePrimitive(const char *name, int kind) : ::cPacket(name,kind)
{
}

TxDonePrimitive::TxDonePrimitive(const TxDonePrimitive& other) : ::cPacket(other)
{
    copy(other);
}

TxDonePrimitive::~TxDonePrimitive()
{
}

TxDonePrimitive& TxDonePrimitive::operator=(const TxDonePrimitive& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void TxDonePrimitive::copy(const TxDonePrimitive& other)
{
}

void TxDonePrimitive::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
}

void TxDonePrimitive::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
}

class TxDonePrimitiveDescriptor : public cClassDescriptor
{
  public:
    TxDonePrimitiveDescriptor();
    virtual ~TxDonePrimitiveDescriptor();

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

Register_ClassDescriptor(TxDonePrimitiveDescriptor);

TxDonePrimitiveDescriptor::TxDonePrimitiveDescriptor() : cClassDescriptor("TxDonePrimitive", "cPacket")
{
}

TxDonePrimitiveDescriptor::~TxDonePrimitiveDescriptor()
{
}

bool TxDonePrimitiveDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<TxDonePrimitive *>(obj)!=NULL;
}

const char *TxDonePrimitiveDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int TxDonePrimitiveDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int TxDonePrimitiveDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *TxDonePrimitiveDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int TxDonePrimitiveDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *TxDonePrimitiveDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *TxDonePrimitiveDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int TxDonePrimitiveDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    TxDonePrimitive *pp = (TxDonePrimitive *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string TxDonePrimitiveDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    TxDonePrimitive *pp = (TxDonePrimitive *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool TxDonePrimitiveDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    TxDonePrimitive *pp = (TxDonePrimitive *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *TxDonePrimitiveDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *TxDonePrimitiveDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    TxDonePrimitive *pp = (TxDonePrimitive *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(setRxModePrimitive);

setRxModePrimitive::setRxModePrimitive(const char *name, int kind) : ::cPacket(name,kind)
{
    this->channel_var = 0;
    this->genTime_var = 0;
}

setRxModePrimitive::setRxModePrimitive(const setRxModePrimitive& other) : ::cPacket(other)
{
    copy(other);
}

setRxModePrimitive::~setRxModePrimitive()
{
}

setRxModePrimitive& setRxModePrimitive::operator=(const setRxModePrimitive& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void setRxModePrimitive::copy(const setRxModePrimitive& other)
{
    this->channel_var = other.channel_var;
    this->genTime_var = other.genTime_var;
}

void setRxModePrimitive::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->channel_var);
    doPacking(b,this->genTime_var);
}

void setRxModePrimitive::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->channel_var);
    doUnpacking(b,this->genTime_var);
}

int setRxModePrimitive::getChannel() const
{
    return channel_var;
}

void setRxModePrimitive::setChannel(int channel)
{
    this->channel_var = channel;
}

double setRxModePrimitive::getGenTime() const
{
    return genTime_var;
}

void setRxModePrimitive::setGenTime(double genTime)
{
    this->genTime_var = genTime;
}

class setRxModePrimitiveDescriptor : public cClassDescriptor
{
  public:
    setRxModePrimitiveDescriptor();
    virtual ~setRxModePrimitiveDescriptor();

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

Register_ClassDescriptor(setRxModePrimitiveDescriptor);

setRxModePrimitiveDescriptor::setRxModePrimitiveDescriptor() : cClassDescriptor("setRxModePrimitive", "cPacket")
{
}

setRxModePrimitiveDescriptor::~setRxModePrimitiveDescriptor()
{
}

bool setRxModePrimitiveDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<setRxModePrimitive *>(obj)!=NULL;
}

const char *setRxModePrimitiveDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int setRxModePrimitiveDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int setRxModePrimitiveDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *setRxModePrimitiveDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "channel",
        "genTime",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int setRxModePrimitiveDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "channel")==0) return base+0;
    if (fieldName[0]=='g' && strcmp(fieldName, "genTime")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *setRxModePrimitiveDescriptor::getFieldTypeString(void *object, int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *setRxModePrimitiveDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int setRxModePrimitiveDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    setRxModePrimitive *pp = (setRxModePrimitive *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string setRxModePrimitiveDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    setRxModePrimitive *pp = (setRxModePrimitive *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getChannel());
        case 1: return double2string(pp->getGenTime());
        default: return "";
    }
}

bool setRxModePrimitiveDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    setRxModePrimitive *pp = (setRxModePrimitive *)object; (void)pp;
    switch (field) {
        case 0: pp->setChannel(string2long(value)); return true;
        case 1: pp->setGenTime(string2double(value)); return true;
        default: return false;
    }
}

const char *setRxModePrimitiveDescriptor::getFieldStructName(void *object, int field) const
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

void *setRxModePrimitiveDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    setRxModePrimitive *pp = (setRxModePrimitive *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(RxNoFramePrimitive);

RxNoFramePrimitive::RxNoFramePrimitive(const char *name, int kind) : ::cPacket(name,kind)
{
}

RxNoFramePrimitive::RxNoFramePrimitive(const RxNoFramePrimitive& other) : ::cPacket(other)
{
    copy(other);
}

RxNoFramePrimitive::~RxNoFramePrimitive()
{
}

RxNoFramePrimitive& RxNoFramePrimitive::operator=(const RxNoFramePrimitive& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void RxNoFramePrimitive::copy(const RxNoFramePrimitive& other)
{
}

void RxNoFramePrimitive::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
}

void RxNoFramePrimitive::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
}

class RxNoFramePrimitiveDescriptor : public cClassDescriptor
{
  public:
    RxNoFramePrimitiveDescriptor();
    virtual ~RxNoFramePrimitiveDescriptor();

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

Register_ClassDescriptor(RxNoFramePrimitiveDescriptor);

RxNoFramePrimitiveDescriptor::RxNoFramePrimitiveDescriptor() : cClassDescriptor("RxNoFramePrimitive", "cPacket")
{
}

RxNoFramePrimitiveDescriptor::~RxNoFramePrimitiveDescriptor()
{
}

bool RxNoFramePrimitiveDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<RxNoFramePrimitive *>(obj)!=NULL;
}

const char *RxNoFramePrimitiveDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int RxNoFramePrimitiveDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int RxNoFramePrimitiveDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *RxNoFramePrimitiveDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int RxNoFramePrimitiveDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *RxNoFramePrimitiveDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *RxNoFramePrimitiveDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int RxNoFramePrimitiveDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    RxNoFramePrimitive *pp = (RxNoFramePrimitive *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string RxNoFramePrimitiveDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    RxNoFramePrimitive *pp = (RxNoFramePrimitive *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool RxNoFramePrimitiveDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    RxNoFramePrimitive *pp = (RxNoFramePrimitive *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *RxNoFramePrimitiveDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *RxNoFramePrimitiveDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    RxNoFramePrimitive *pp = (RxNoFramePrimitive *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(RxReadyPrimitive);

RxReadyPrimitive::RxReadyPrimitive(const char *name, int kind) : ::cPacket(name,kind)
{
}

RxReadyPrimitive::RxReadyPrimitive(const RxReadyPrimitive& other) : ::cPacket(other)
{
    copy(other);
}

RxReadyPrimitive::~RxReadyPrimitive()
{
}

RxReadyPrimitive& RxReadyPrimitive::operator=(const RxReadyPrimitive& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void RxReadyPrimitive::copy(const RxReadyPrimitive& other)
{
}

void RxReadyPrimitive::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
}

void RxReadyPrimitive::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
}

class RxReadyPrimitiveDescriptor : public cClassDescriptor
{
  public:
    RxReadyPrimitiveDescriptor();
    virtual ~RxReadyPrimitiveDescriptor();

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

Register_ClassDescriptor(RxReadyPrimitiveDescriptor);

RxReadyPrimitiveDescriptor::RxReadyPrimitiveDescriptor() : cClassDescriptor("RxReadyPrimitive", "cPacket")
{
}

RxReadyPrimitiveDescriptor::~RxReadyPrimitiveDescriptor()
{
}

bool RxReadyPrimitiveDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<RxReadyPrimitive *>(obj)!=NULL;
}

const char *RxReadyPrimitiveDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int RxReadyPrimitiveDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int RxReadyPrimitiveDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *RxReadyPrimitiveDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int RxReadyPrimitiveDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *RxReadyPrimitiveDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *RxReadyPrimitiveDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int RxReadyPrimitiveDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    RxReadyPrimitive *pp = (RxReadyPrimitive *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string RxReadyPrimitiveDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    RxReadyPrimitive *pp = (RxReadyPrimitive *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool RxReadyPrimitiveDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    RxReadyPrimitive *pp = (RxReadyPrimitive *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *RxReadyPrimitiveDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *RxReadyPrimitiveDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    RxReadyPrimitive *pp = (RxReadyPrimitive *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(confirmSetRxModePrimitive);

confirmSetRxModePrimitive::confirmSetRxModePrimitive(const char *name, int kind) : ::cPacket(name,kind)
{
}

confirmSetRxModePrimitive::confirmSetRxModePrimitive(const confirmSetRxModePrimitive& other) : ::cPacket(other)
{
    copy(other);
}

confirmSetRxModePrimitive::~confirmSetRxModePrimitive()
{
}

confirmSetRxModePrimitive& confirmSetRxModePrimitive::operator=(const confirmSetRxModePrimitive& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void confirmSetRxModePrimitive::copy(const confirmSetRxModePrimitive& other)
{
}

void confirmSetRxModePrimitive::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
}

void confirmSetRxModePrimitive::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
}

class confirmSetRxModePrimitiveDescriptor : public cClassDescriptor
{
  public:
    confirmSetRxModePrimitiveDescriptor();
    virtual ~confirmSetRxModePrimitiveDescriptor();

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

Register_ClassDescriptor(confirmSetRxModePrimitiveDescriptor);

confirmSetRxModePrimitiveDescriptor::confirmSetRxModePrimitiveDescriptor() : cClassDescriptor("confirmSetRxModePrimitive", "cPacket")
{
}

confirmSetRxModePrimitiveDescriptor::~confirmSetRxModePrimitiveDescriptor()
{
}

bool confirmSetRxModePrimitiveDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<confirmSetRxModePrimitive *>(obj)!=NULL;
}

const char *confirmSetRxModePrimitiveDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int confirmSetRxModePrimitiveDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount(object) : 0;
}

unsigned int confirmSetRxModePrimitiveDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return 0;
}

const char *confirmSetRxModePrimitiveDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

int confirmSetRxModePrimitiveDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *confirmSetRxModePrimitiveDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

const char *confirmSetRxModePrimitiveDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int confirmSetRxModePrimitiveDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    confirmSetRxModePrimitive *pp = (confirmSetRxModePrimitive *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string confirmSetRxModePrimitiveDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    confirmSetRxModePrimitive *pp = (confirmSetRxModePrimitive *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool confirmSetRxModePrimitiveDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    confirmSetRxModePrimitive *pp = (confirmSetRxModePrimitive *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *confirmSetRxModePrimitiveDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    return NULL;
}

void *confirmSetRxModePrimitiveDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    confirmSetRxModePrimitive *pp = (confirmSetRxModePrimitive *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(getReceivedDataPrimitive);

getReceivedDataPrimitive::getReceivedDataPrimitive(const char *name, int kind) : ::cPacket(name,kind)
{
    this->genTime_var = 0;
}

getReceivedDataPrimitive::getReceivedDataPrimitive(const getReceivedDataPrimitive& other) : ::cPacket(other)
{
    copy(other);
}

getReceivedDataPrimitive::~getReceivedDataPrimitive()
{
}

getReceivedDataPrimitive& getReceivedDataPrimitive::operator=(const getReceivedDataPrimitive& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void getReceivedDataPrimitive::copy(const getReceivedDataPrimitive& other)
{
    this->genTime_var = other.genTime_var;
}

void getReceivedDataPrimitive::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->genTime_var);
}

void getReceivedDataPrimitive::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->genTime_var);
}

double getReceivedDataPrimitive::getGenTime() const
{
    return genTime_var;
}

void getReceivedDataPrimitive::setGenTime(double genTime)
{
    this->genTime_var = genTime;
}

class getReceivedDataPrimitiveDescriptor : public cClassDescriptor
{
  public:
    getReceivedDataPrimitiveDescriptor();
    virtual ~getReceivedDataPrimitiveDescriptor();

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

Register_ClassDescriptor(getReceivedDataPrimitiveDescriptor);

getReceivedDataPrimitiveDescriptor::getReceivedDataPrimitiveDescriptor() : cClassDescriptor("getReceivedDataPrimitive", "cPacket")
{
}

getReceivedDataPrimitiveDescriptor::~getReceivedDataPrimitiveDescriptor()
{
}

bool getReceivedDataPrimitiveDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<getReceivedDataPrimitive *>(obj)!=NULL;
}

const char *getReceivedDataPrimitiveDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int getReceivedDataPrimitiveDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int getReceivedDataPrimitiveDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *getReceivedDataPrimitiveDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "genTime",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int getReceivedDataPrimitiveDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='g' && strcmp(fieldName, "genTime")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *getReceivedDataPrimitiveDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "double",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *getReceivedDataPrimitiveDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int getReceivedDataPrimitiveDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    getReceivedDataPrimitive *pp = (getReceivedDataPrimitive *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string getReceivedDataPrimitiveDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    getReceivedDataPrimitive *pp = (getReceivedDataPrimitive *)object; (void)pp;
    switch (field) {
        case 0: return double2string(pp->getGenTime());
        default: return "";
    }
}

bool getReceivedDataPrimitiveDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    getReceivedDataPrimitive *pp = (getReceivedDataPrimitive *)object; (void)pp;
    switch (field) {
        case 0: pp->setGenTime(string2double(value)); return true;
        default: return false;
    }
}

const char *getReceivedDataPrimitiveDescriptor::getFieldStructName(void *object, int field) const
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

void *getReceivedDataPrimitiveDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    getReceivedDataPrimitive *pp = (getReceivedDataPrimitive *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

Register_Class(startTxPrimitive);

startTxPrimitive::startTxPrimitive(const char *name, int kind) : ::cPacket(name,kind)
{
    this->genTime_var = 0;
}

startTxPrimitive::startTxPrimitive(const startTxPrimitive& other) : ::cPacket(other)
{
    copy(other);
}

startTxPrimitive::~startTxPrimitive()
{
}

startTxPrimitive& startTxPrimitive::operator=(const startTxPrimitive& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void startTxPrimitive::copy(const startTxPrimitive& other)
{
    this->genTime_var = other.genTime_var;
}

void startTxPrimitive::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->genTime_var);
}

void startTxPrimitive::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->genTime_var);
}

double startTxPrimitive::getGenTime() const
{
    return genTime_var;
}

void startTxPrimitive::setGenTime(double genTime)
{
    this->genTime_var = genTime;
}

class startTxPrimitiveDescriptor : public cClassDescriptor
{
  public:
    startTxPrimitiveDescriptor();
    virtual ~startTxPrimitiveDescriptor();

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

Register_ClassDescriptor(startTxPrimitiveDescriptor);

startTxPrimitiveDescriptor::startTxPrimitiveDescriptor() : cClassDescriptor("startTxPrimitive", "cPacket")
{
}

startTxPrimitiveDescriptor::~startTxPrimitiveDescriptor()
{
}

bool startTxPrimitiveDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<startTxPrimitive *>(obj)!=NULL;
}

const char *startTxPrimitiveDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int startTxPrimitiveDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount(object) : 1;
}

unsigned int startTxPrimitiveDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *startTxPrimitiveDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "genTime",
    };
    return (field>=0 && field<1) ? fieldNames[field] : NULL;
}

int startTxPrimitiveDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='g' && strcmp(fieldName, "genTime")==0) return base+0;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *startTxPrimitiveDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "double",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : NULL;
}

const char *startTxPrimitiveDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int startTxPrimitiveDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    startTxPrimitive *pp = (startTxPrimitive *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string startTxPrimitiveDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    startTxPrimitive *pp = (startTxPrimitive *)object; (void)pp;
    switch (field) {
        case 0: return double2string(pp->getGenTime());
        default: return "";
    }
}

bool startTxPrimitiveDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    startTxPrimitive *pp = (startTxPrimitive *)object; (void)pp;
    switch (field) {
        case 0: pp->setGenTime(string2double(value)); return true;
        default: return false;
    }
}

const char *startTxPrimitiveDescriptor::getFieldStructName(void *object, int field) const
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

void *startTxPrimitiveDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    startTxPrimitive *pp = (startTxPrimitive *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


