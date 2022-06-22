/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "troves_of_the_thunder_king.h"

class instance_troves_of_the_thunder_king : public InstanceMapScript
{
public:
    instance_troves_of_the_thunder_king() : InstanceMapScript("instance_troves_of_the_thunder_king", 1135) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_troves_of_the_thunder_king_InstanceMapScript(map);
    }

    struct instance_troves_of_the_thunder_king_InstanceMapScript : public InstanceScript
    {
        instance_troves_of_the_thunder_king_InstanceMapScript(Map* map) : InstanceScript(map)
        { }

        void Initialize()
        {
            start = NOT_STARTED;
            pilarMasterGUIDs.clear();
        }

        void OnPlayerEnter(Player* player)
        {
            std::set<uint32> WorldMapAreaIds;
            WorldMapAreaIds.insert(770);
            WorldMapAreaIds.insert(748);
            WorldMapAreaIds.insert(907);
            WorldMapAreaIds.insert(910);
            player->GetSession()->SendSetPhaseShift(std::set<uint32>(), std::set<uint32>(), WorldMapAreaIds, 8);
        }
		
        void OnCreatureCreate(Creature* creature)
        {
            switch (creature->GetEntry())
            {
                case NPC_LIGHTING_PILAR_TARGET_BUNNY:
                    creature->SetReactState(REACT_PASSIVE);
                    break;
                case NPC_LIGHTING_PILAR_MASTER_BUNNY:
                    pilarMasterGUIDs.push_back(creature->GetGUID());
                    break;
                default:
                    break;
            }
        }

        void SetData(uint32 type, uint32 data)
        {
            switch (type)
            {
                case DATA_EVENT_STARTED:
                    start = data;
                    if (data == DONE)
                        for (std::vector<uint64>::const_iterator itr = pilarMasterGUIDs.begin(); itr != pilarMasterGUIDs.end(); ++itr)
                            if (Creature* cre = instance->GetCreature(*itr))
                                cre->AI()->DoAction(ACTION_1);
                    break;
                default:
                    break;
            }
        }

        uint32 GetData(uint32 type)
        {
            switch (type)
            {
                case DATA_EVENT_STARTED:
                    return start;
                default:
                    return 0;
            }
        }

    private:
        uint32 start;
        std::vector<uint64> pilarMasterGUIDs;
    };
};

void AddSC_instance_troves_of_the_thunder_king()
{
    new instance_troves_of_the_thunder_king();
}
