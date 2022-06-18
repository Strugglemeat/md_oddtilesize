#include <genesis.h>
#include <resources.h>

char debug_string[40] = "";

void print_debug();

void draw_tile(u8 tileSize, u8 xPos, u8 yPos);

int main()
{
    VDP_clearPlane(BG_B,TRUE);
    VDP_clearPlane(BG_A,TRUE);

    SYS_disableInts();

    VDP_setScreenWidth320();
    VDP_setScreenHeight224();

    VDP_loadFontData(tileset_Font_Namco.tiles, 96, CPU);
    
    VDP_setPalette(PAL3,tile08.palette->data);
    VDP_loadTileSet(tile08.tileset,1,CPU);
    VDP_loadTileSet(tile09top.tileset,2,CPU);
    VDP_loadTileSet(tile09right.tileset,3,CPU);
    VDP_loadTileSet(tile09corner.tileset,4,CPU);
    VDP_loadTileSet(tile12top.tileset,5,CPU);
    VDP_loadTileSet(tile12right.tileset,6,CPU);
    VDP_loadTileSet(tile12corner.tileset,7,CPU);
    VDP_loadTileSet(tile14top.tileset,8,CPU);
    VDP_loadTileSet(tile14right.tileset,9,CPU);
    VDP_loadTileSet(tile14corner.tileset,10,CPU);

    SYS_enableInts();

    while(1)
    {
    SYS_doVBlankProcess();

    draw_tile(8,1,16);//size, x, y

    draw_tile(9,3,16);

    draw_tile(12,5,16);

    draw_tile(14,8,16);

    draw_tile(16,11,16);

    print_debug();
    }
    
    return 0;
}

void draw_tile(u8 tileSize, u8 xPos, u8 yPos)
{
    switch (tileSize)
    {
        case 8:
        VDP_fillTileMapRect(BG_A, TILE_ATTR_FULL(PAL3, FALSE, FALSE, FALSE, 1), xPos, yPos, 1, 1);
        break;

        case 9:
        VDP_fillTileMapRect(BG_A, TILE_ATTR_FULL(PAL3, FALSE, FALSE, FALSE, 1), xPos, yPos, 1, 1);
        VDP_fillTileMapRect(BG_A, TILE_ATTR_FULL(PAL3, FALSE, FALSE, FALSE, 2), xPos, yPos-1, 1, 1);//top
        VDP_fillTileMapRect(BG_A, TILE_ATTR_FULL(PAL3, FALSE, FALSE, FALSE, 3), xPos+1, yPos, 1, 1);//right
        VDP_fillTileMapRect(BG_A, TILE_ATTR_FULL(PAL3, FALSE, FALSE, FALSE, 4), xPos+1, yPos-1, 1, 1);//corner
        break;

        case 12:
        VDP_fillTileMapRect(BG_A, TILE_ATTR_FULL(PAL3, FALSE, FALSE, FALSE, 1), xPos, yPos, 1, 1);
        VDP_fillTileMapRect(BG_A, TILE_ATTR_FULL(PAL3, FALSE, FALSE, FALSE, 5), xPos, yPos-1, 1, 1);//top
        VDP_fillTileMapRect(BG_A, TILE_ATTR_FULL(PAL3, FALSE, FALSE, FALSE, 6), xPos+1, yPos, 1, 1);//right
        VDP_fillTileMapRect(BG_A, TILE_ATTR_FULL(PAL3, FALSE, FALSE, FALSE, 7), xPos+1, yPos-1, 1, 1);//corner
        break;

        case 14:
        VDP_fillTileMapRect(BG_A, TILE_ATTR_FULL(PAL3, FALSE, FALSE, FALSE, 1), xPos, yPos, 1, 1);
        VDP_fillTileMapRect(BG_A, TILE_ATTR_FULL(PAL3, FALSE, FALSE, FALSE, 8), xPos, yPos-1, 1, 1);//top
        VDP_fillTileMapRect(BG_A, TILE_ATTR_FULL(PAL3, FALSE, FALSE, FALSE, 9), xPos+1, yPos, 1, 1);//right
        VDP_fillTileMapRect(BG_A, TILE_ATTR_FULL(PAL3, FALSE, FALSE, FALSE, 10), xPos+1, yPos-1, 1, 1);//corner
        break;

        case 16:
        VDP_fillTileMapRect(BG_A, TILE_ATTR_FULL(PAL3, FALSE, FALSE, FALSE, 1), xPos, yPos-1, 2, 2);
        break;
    }
    
}

void print_debug()
{
    sprintf(debug_string,"FPS:%ld", SYS_getFPS());
    VDP_drawText(debug_string,32,0);

    //sprintf(debug_string,"P1 piece #:%d", P1.pieceNumIncrementer);
    //VDP_drawText(debug_string,30,1);
}