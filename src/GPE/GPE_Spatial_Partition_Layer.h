/*
GPE_Spatial_Partition_Layer.h
This file is part of:
GAME PENCIL ENGINE
https://create.pawbyte.com
Copyright (c) 2014-2020 Nathan Hurde, Chase Lee.

Copyright (c) 2014-2020 PawByte LLC.
Copyright (c) 2014-2020 Game Pencil Engine contributors ( Contributors Page )

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the “Software”), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

-Game Pencil Engine <https://create.pawbyte.com>


*/

#ifndef GPE_SPATIAL_PARTITIONS_LAYER_H
#define GPE_SPATIAL_PARTITIONS_LAYER_H

#include "GPE_Spatial_Partition.h"

class GPE_Spatial_Partition_Layer
{
    protected:
        std::vector<GPE_SpatialPartition * > layerPartitions; //Used for spatial partitioning collision checker
        bool superDebugCollisions;
        bool spatialGridIsCreated;

        std::map<std::string,bool> objectCollisionIsChecked;
        std::vector<GPE_GameObject * > collisionPairA;
        std::vector<GPE_GameObject * > collisionPairB;
        int layerID;
        bool isActive;
        int spatialGridWidthSize ,  spatialGridHeightSize;
        int spatialGridWidthAmount, spatialGridHeightAmount;
    public:
        GPE_Spatial_Partition_Layer( int myLayerId );
        ~GPE_Spatial_Partition_Layer();
        void activate_layer();
        void add_object( GPE_GameObject * gameObject );
        void check_collisions_self();
        void check_collisions_with_layer( GPE_Spatial_Partition_Layer * otherLayer);
        void clear_spaces();
        void deactivate_layer();
        int find_spatial_at( int xIn, int yIn);
        void init_spatialpartioning( int cSceneWidth, int cSceneHeight );
        bool is_active();
        void remove_object( GPE_GameObject * gameObject );
};

#endif //GPE_SPATIAL_PARTITIONS_LAYER_H
