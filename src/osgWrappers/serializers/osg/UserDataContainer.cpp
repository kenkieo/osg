#include <osg/UserDataContainer>

#include <osgDB/ObjectWrapper>
#include <osgDB/InputStream>
#include <osgDB/OutputStream>

static bool checkUDC_UserData( const osg::UserDataContainer& udc )
{
    return dynamic_cast<const osg::Object*>(udc.getUserData())!=0;
}

static bool readUDC_UserData( osgDB::InputStream& is, osg::UserDataContainer& udc )
{
    is >> osgDB::BEGIN_BRACKET;
    osg::Object* object = is.readObject();
    if(object) udc.setUserData(object);
    is >> osgDB::END_BRACKET;
    return true;
}

static bool writeUDC_UserData( osgDB::OutputStream& os, const osg::UserDataContainer& udc )
{
    os << osgDB::BEGIN_BRACKET << std::endl;
    os.writeObject(dynamic_cast<const osg::Object*>(udc.getUserData()));
    os << osgDB::END_BRACKET << std::endl;
    return true;
}

// _descriptions
static bool checkUDC_Descriptions( const osg::UserDataContainer& udc )
{
    return udc.getNumDescriptions()>0;
}

static bool readUDC_Descriptions( osgDB::InputStream& is, osg::UserDataContainer& udc )
{
    unsigned int size = is.readSize(); is >> osgDB::BEGIN_BRACKET;
    for ( unsigned int i=0; i<size; ++i )
    {
        std::string value;
        is.readWrappedString( value );
        udc.addDescription( value );
    }
    is >> osgDB::END_BRACKET;
    return true;
}

static bool writeUDC_Descriptions( osgDB::OutputStream& os, const osg::UserDataContainer& udc )
{
    const osg::Object::DescriptionList& slist = udc.getDescriptions();
    os.writeSize(slist.size()); os << osgDB::BEGIN_BRACKET << std::endl;
    for ( osg::Object::DescriptionList::const_iterator itr=slist.begin();
          itr!=slist.end(); ++itr )
    {
        os.writeWrappedString( *itr );
        os << std::endl;
    }
    os << osgDB::END_BRACKET << std::endl;
    return true;
}


static bool checkUDC_UserObjects( const osg::UserDataContainer& udc )
{
    return udc.getNumUserObjects()>0;
}

static bool readUDC_UserObjects( osgDB::InputStream& is, osg::UserDataContainer& udc )
{
    unsigned int size = is.readSize(); is >> osgDB::BEGIN_BRACKET;
    for( unsigned int i=0; i<size; ++i )
    {
        osg::Object* read_object = is.readObject();
        if (read_object) udc.addUserObject( read_object );
    }
    is >> osgDB::END_BRACKET;
    return true;
}

static bool writeUDC_UserObjects( osgDB::OutputStream& os, const osg::UserDataContainer& udc )
{
    unsigned int numObjects = udc.getNumUserObjects();
    os.writeSize(numObjects); os << osgDB::BEGIN_BRACKET << std::endl;
    for ( unsigned int i=0; i<numObjects; ++i )
    {
        os << udc.getUserObject(i);
    }
    os << osgDB::END_BRACKET << std::endl;
    return true;
}



REGISTER_OBJECT_WRAPPER( UserDataContainer,
                         new osg::UserDataContainer,
                         osg::UserDataContainer,
                         "osg::Object osg::UserDataContainer" )
{
    ADD_USER_SERIALIZER( UDC_UserData );  // _userData
    ADD_USER_SERIALIZER( UDC_Descriptions );  // _descriptions
    ADD_USER_SERIALIZER( UDC_UserObjects );  // _userData
}
