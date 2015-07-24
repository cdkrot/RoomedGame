#include "entity/entity.h"
#include "entity-mgr.h"

Entity::Entity(EntityMgr& mgr): id(mgr.registerNewEntity())
{
	
}