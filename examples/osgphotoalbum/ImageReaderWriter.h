/* -*-c++-*- OpenSceneGraph - Copyright (C) 1998-2003 Robert Osfield 
 *
 * This application is open source and may be redistributed and/or modified under  
 * the terms of the GNU Public License (GPL) version 1.0 or 
 * (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
 * OpenSceneGraph Public License for more details.
*/

#ifndef IMAGEREADERWRITER_H
#define IMAGEREADERWRITER_H

#include <osgDB/ReadFile>
#include <osgDB/WriteFile>
#include <osgDB/ImageOptions>

#include "PhotoArchive.h"

class ImageReaderWriter : public osgDB::ReaderWriter
{
    public:
        
        ImageReaderWriter();
        
        virtual const char* className() { return "ImageReader"; }

        void addPhotoArchive(PhotoArchive* archive) { _photoArchiveList.push_back(archive); }

        std::string insertReference(const std::string& fileName, unsigned int res, float width, float height, bool backPage);

        virtual ReadResult readNode(const std::string& fileName, const Options*);
        
    protected:


        struct DataReference
        {
            DataReference();
            DataReference(const std::string& fileName, unsigned int res, float width, float height,bool backPage);
            DataReference(const DataReference& rhs);

            std::string     _fileName;
            unsigned int    _resolutionX;
            unsigned int    _resolutionY;
            osg::Vec3       _center;
            osg::Vec3       _maximumWidth; 
            osg::Vec3       _maximumHeight;
            unsigned int    _numPointsAcross; 
            unsigned int    _numPointsUp;
            bool            _backPage;
        };
        
        osg::Image* readImage_Archive(DataReference& dr, float& s,float& t);
        
        osg::Image* readImage_DynamicSampling(DataReference& dr, float& s,float& t);

        typedef std::map< std::string,DataReference > DataReferenceMap;
        typedef std::vector< osg::ref_ptr<PhotoArchive> > PhotoArchiveList;

        DataReferenceMap            _dataReferences;
        PhotoArchiveList            _photoArchiveList;


};

#endif
