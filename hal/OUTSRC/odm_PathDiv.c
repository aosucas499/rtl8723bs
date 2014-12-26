/******************************************************************************
 *
 * Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved.
 *                                        
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 *
 ******************************************************************************/

//============================================================
// include files
//============================================================
#include "odm_precomp.h"



VOID
odm_PathDiversityInit(
	IN	PVOID	pDM_VOID
)
{
#if(DM_ODM_SUPPORT_TYPE & ODM_CE)
	PDM_ODM_T		pDM_Odm = (PDM_ODM_T)pDM_VOID;
	if(!(pDM_Odm->SupportAbility & ODM_BB_PATH_DIV))
	{
		ODM_RT_TRACE(pDM_Odm, ODM_COMP_PATH_DIV,ODM_DBG_LOUD,("Return: Not Support PathDiv\n"));
		return;
	}

#if RTL8812A_SUPPORT

	if(pDM_Odm->SupportICType & ODM_RTL8812)
		ODM_PathDiversityInit_8812A(pDM_Odm);
#endif	
#endif
}

#if(DM_ODM_SUPPORT_TYPE & ODM_CE)
VOID
odm_PathDiversity(
	IN	PVOID	pDM_VOID
)
{
	PDM_ODM_T		pDM_Odm = (PDM_ODM_T)pDM_VOID;
	if(!(pDM_Odm->SupportAbility & ODM_BB_PATH_DIV))
	{
		ODM_RT_TRACE(pDM_Odm, ODM_COMP_PATH_DIV,ODM_DBG_LOUD,("Return: Not Support PathDiv\n"));
		return;
	}

#if RTL8812A_SUPPORT

	if(pDM_Odm->SupportICType & ODM_RTL8812)
		ODM_PathDiversity_8812A(pDM_Odm);
#endif	
}
#endif  //(DM_ODM_SUPPORT_TYPE & ODM_CE)
