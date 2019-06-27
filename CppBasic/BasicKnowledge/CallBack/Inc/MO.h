/*
 * 作用：通过一个MOCODE对应一个结构体的方式，来约定BOSS和Employee之间的接口
*/

#ifndef OM_MOCODE_H
#define OM_MOCODE_H

#define OAM_SUBSYSA_GETXXX 10
#define OAM_SUBSYSB_SETXXX 20

/*
 * OAM_SUBSYSA_GETXXX
*/
typedef struct 
{
    int cell_id;
    int nr_pci;
    int tag_mcc1;
    int tag_mcc2;
    bool prts_enable;
}oam_subsysa_cellconfig;



#endif