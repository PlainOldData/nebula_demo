#define NEB_SUGAR_IMPL
#include <nebula/sugar.h>

#define NEB_GLFW_IMPL
#include "nebula_glfw.h"

#define NEB_OGL3_IMPL
#include "nebula_ogl.h"

#include <stdio.h>


/* ----------------------------------------------------------- Application -- */


struct nb_sugar_ctx nb_sugar_ctx;
struct nb_glfw_ctx glfw_ctx;


int
main() {
        nbs_init(&nb_sugar_ctx);
        nb_glfw_setup(&glfw_ctx, &nb_sugar_ctx);

        nbc_ctx_t nbc_ctx = 0;
        nbr_ctx_t nbr_ctx = 0;

        nbs_ctx_get_ctx(&nb_sugar_ctx, &nbc_ctx, &nbr_ctx);

        while(nb_glfw_tick(&glfw_ctx, &nb_sugar_ctx)) {

                nbs_frame_begin(&nb_sugar_ctx);

                /* hello world */
                const struct nb_window * vi = 0;

                vi = nbs_window_begin(&nb_sugar_ctx, "hello", 0xFF0000FF);
                if(nbs_button(&nb_sugar_ctx, vi, "foo")) {
                        printf("Clicked\n");
                }
                nbs_window_end(&nb_sugar_ctx, vi);

                vi = nbs_window_begin(&nb_sugar_ctx, "world", 0x0000FFFF);
                nbs_window_end(&nb_sugar_ctx, vi);

                nbs_frame_submit(&nb_sugar_ctx);

                glClearColor(0.157, 0.153, 0.161, 1);
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                nbgl_render(
                            glfw_ctx.display_width,
                            glfw_ctx.display_height,
                            &glfw_ctx.gl_ctx,
                            nbr_ctx);
        };

        return 0;
}
