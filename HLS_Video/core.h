#include "hls_video.h"
#include <hls_stream.h>
#include <hls/hls_video_types.h>
#include <stdint.h>

// use the axi-stream side channel
#include <ap_axi_sdata.h>



#define IMG_WIDTH_OR_COLS 638
#define IMG_HEIGHT_OR_ROWS 478

#define KERNEL_DIM 3

#define INPUT_IMAGE_CORE "E:\\Joshua_BTP\\images\\video_crop.avi"
#define OUTPUT_IMAGE_CORE "E:\\Joshua_BTP\\images\\out_video.avi"



typedef hls::stream<ap_axiu<24,1,1,1> >			AXI_IN_STREAM;
typedef hls::stream<ap_axiu<8,1,1,1> >			AXI_OUT_STREAM;
typedef hls::Mat<IMG_HEIGHT_OR_ROWS, IMG_WIDTH_OR_COLS, HLS_8UC1> GRAY_IMAGE;
typedef hls::Window<KERNEL_DIM,KERNEL_DIM,char> WINDOW;

extern unsigned int expArray[256];

// IP core
void doAniso(AXI_IN_STREAM &instream, AXI_OUT_STREAM &outstream);
void anisotropic_diffusion(GRAY_IMAGE& img_in, GRAY_IMAGE& img_out,WINDOW left_kernel,WINDOW right_kernel,WINDOW up_kernel,WINDOW down_kernel,unsigned int expArray[256]);
