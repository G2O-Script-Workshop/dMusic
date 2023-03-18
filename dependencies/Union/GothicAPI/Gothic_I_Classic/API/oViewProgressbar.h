﻿// Supported with union (c) 2018-2022 Union team
// Licence: GNU General Public License

#ifndef __OVIEW_PROGRESSBAR_H__VER0__
#define __OVIEW_PROGRESSBAR_H__VER0__

#include "zViewProgressbar.h"


  // sizeof 138h
  class oCViewGothicProgressBar : public zCViewProgressBar {
  public:
    int progressbar_sizex; // sizeof 04h    offset 130h

    oCViewGothicProgressBar() : zCtor( zCViewProgressBar ) {}
    /* for zCViewBase num : 14*/
    virtual ~oCViewGothicProgressBar() zCall( 0x00638440 );
    virtual void Init()                zCall( 0x00439830 );
    virtual void HandleChange()        zCall( 0x00439870 );
    /* for zCInputCallback num : 1*/

    // user API
    #include "oCViewGothicProgressBar.inl"
  };


#endif // __OVIEW_PROGRESSBAR_H__VER0__