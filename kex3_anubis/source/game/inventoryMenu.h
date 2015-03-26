//
// Copyright(C) 2014-2015 Samuel Villarreal
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//

#ifndef __INVENTORY_MENU_H__
#define __INVENTORY_MENU_H__

class kexInventoryMenu
{
public:
    kexInventoryMenu(void);
    ~kexInventoryMenu(void);
    
    void                    Init(void);
    void                    Display(void);
    void                    Reset(void);
    void                    Update(void);
    bool                    ProcessInput(inputEvent_t *ev);
    void                    Toggle(void);

    const bool              IsActive(void) { return bActive; }
    
private:
    void                    DrawLeftArrow(void);
    void                    DrawRightArrow(void);
    bool                    CursorOnLeftArrow(float &mx, float &my);
    bool                    CursorOnRightArrow(float &mx, float &my);
    void                    DrawBackground(void);
    void                    DrawButtons(void);
    void                    DrawKeys(void);
    void                    DrawAutomap(void);
    void                    DrawArtifacts(void);
    void                    DrawCenteredImage(kexTexture *texture, const float x, const float y);

    kexTexture              *keyTextures[2][4];
    kexTexture              *artifactTextures[6];
    kexTexture              *weaponTextures[NUMPLAYERWEAPONS];
    kexTexture              *buttonTexture[2];
    kexTexture              *arrows[2];
    kexTexture              *mapClosedTexture;
    kexTexture              *mapOpenTexture;
    kexFont                 *font;
    bool                    bActive;
    bool                    bButtonPressed[4];
    short                   categorySelected;
    short                   artifactSelected;
};

#endif
