    
    #include "threads.h"

    void threads_start(objects * objs) {

        unsigned int iSink;

        // +----------------------------------------------------------+
        // | Raw                                                      |
        // +----------------------------------------------------------+  

            // +------------------------------------------------------+
            // | Source                                               |
            // +------------------------------------------------------+  

                thread_start(objs->asrc_hops_raw_object->thread);

            // +------------------------------------------------------+
            // | Sinks                                                |
            // +------------------------------------------------------+                      

                for (iSink = 0; iSink < objs->asnk_hops_raw_object_count; iSink++) {
                    thread_start(objs->asnk_hops_raw_objects[iSink]->thread);
                }

            // +------------------------------------------------------+
            // | Connector                                            |
            // +------------------------------------------------------+                     

                thread_start(objs->acon_hops_raw_object->thread);

        // +----------------------------------------------------------+
        // | Mapping                                                  |
        // +----------------------------------------------------------+  

            // +------------------------------------------------------+
            // | Module                                               |
            // +------------------------------------------------------+  

                thread_start(objs->amod_mapping_object->thread);

            // +------------------------------------------------------+
            // | Sinks                                                |
            // +------------------------------------------------------+                      

                for (iSink = 0; iSink < objs->asnk_hops_mapping_object_count; iSink++) {
                    thread_start(objs->asnk_hops_mapping_objects[iSink]->thread);
                }

            // +------------------------------------------------------+
            // | Connector                                            |
            // +------------------------------------------------------+                     

                thread_start(objs->acon_hops_mapping_object->thread);

        // +----------------------------------------------------------+
        // | Resample                                                 |
        // +----------------------------------------------------------+  

            // +------------------------------------------------------+
            // | Module                                               |
            // +------------------------------------------------------+  

                thread_start(objs->amod_resample_object->thread);

            // +------------------------------------------------------+
            // | Sinks                                                |
            // +------------------------------------------------------+                      

                for (iSink = 0; iSink < objs->asnk_hops_resample_object_count; iSink++) {
                    thread_start(objs->asnk_hops_resample_objects[iSink]->thread);
                }

            // +------------------------------------------------------+
            // | Connector                                            |
            // +------------------------------------------------------+                     

                thread_start(objs->acon_hops_resample_object->thread);

        // +----------------------------------------------------------+
        // | STFT                                                     |
        // +----------------------------------------------------------+  

            // +------------------------------------------------------+
            // | Module                                               |
            // +------------------------------------------------------+  

                thread_start(objs->amod_stft_object->thread);

            // +------------------------------------------------------+
            // | Sinks                                                |
            // +------------------------------------------------------+                      

                for (iSink = 0; iSink < objs->asnk_spectra_stft_object_count; iSink++) {
                    thread_start(objs->asnk_spectra_stft_objects[iSink]->thread);
                }

            // +------------------------------------------------------+
            // | Connector                                            |
            // +------------------------------------------------------+                     

                thread_start(objs->acon_spectra_stft_object->thread);

        // +----------------------------------------------------------+
        // | SSL                                                      |
        // +----------------------------------------------------------+  

            // +------------------------------------------------------+
            // | Module                                               |
            // +------------------------------------------------------+  

                thread_start(objs->amod_ssl_object->thread);

            // +------------------------------------------------------+
            // | Sinks                                                |
            // +------------------------------------------------------+                      

                for (iSink = 0; iSink < objs->asnk_pots_ssl_object_count; iSink++) {
                    thread_start(objs->asnk_pots_ssl_objects[iSink]->thread);
                }

            // +------------------------------------------------------+
            // | Connector                                            |
            // +------------------------------------------------------+                     

                thread_start(objs->acon_pots_ssl_object->thread);

        // +----------------------------------------------------------+
        // | SST                                                      |
        // +----------------------------------------------------------+  

            // +------------------------------------------------------+
            // | Module                                               |
            // +------------------------------------------------------+  

                thread_start(objs->amod_sst_object->thread);

            // +------------------------------------------------------+
            // | Sinks                                                |
            // +------------------------------------------------------+                      

                for (iSink = 0; iSink < objs->asnk_tracks_sst_object_count; iSink++) {
                    thread_start(objs->asnk_tracks_sst_objects[iSink]->thread);
                }

            // +------------------------------------------------------+
            // | Connector                                            |
            // +------------------------------------------------------+                     

                thread_start(objs->acon_tracks_sst_object->thread);

        // +----------------------------------------------------------+
        // | SSS                                                      |
        // +----------------------------------------------------------+  

            // +------------------------------------------------------+
            // | Module                                               |
            // +------------------------------------------------------+  

                thread_start(objs->amod_sss_object->thread);

            // +------------------------------------------------------+
            // | Sinks                                                |
            // +------------------------------------------------------+                      

                for (iSink = 0; iSink < objs->asnk_spectra_sss_object_count; iSink++) {
                    thread_start(objs->asnk_spectra_sss_objects[iSink]->thread);
                }

            // +------------------------------------------------------+
            // | Connector                                            |
            // +------------------------------------------------------+                     

                thread_start(objs->acon_spectra_sss_object->thread);

        // +----------------------------------------------------------+
        // | SSPF                                                     |
        // +----------------------------------------------------------+  

            // +------------------------------------------------------+
            // | Module                                               |
            // +------------------------------------------------------+  

                thread_start(objs->amod_sspf_object->thread);

            // +------------------------------------------------------+
            // | Sinks                                                |
            // +------------------------------------------------------+                      

                for (iSink = 0; iSink < objs->asnk_spectra_sspf_object_count; iSink++) {
                    thread_start(objs->asnk_spectra_sspf_objects[iSink]->thread);
                }

            // +------------------------------------------------------+
            // | Connector                                            |
            // +------------------------------------------------------+                     

                thread_start(objs->acon_spectra_sspf_object->thread);

    }

    void threads_stop(objects * objs) {

        // +----------------------------------------------------------+
        // | Raw                                                      |
        // +----------------------------------------------------------+  

            // +------------------------------------------------------+
            // | Source                                               |
            // +------------------------------------------------------+  

                thread_stop(objs->asrc_hops_raw_object->thread);

                // Stops the source that generate frames to process.
                // This will generate a "zero" message that will stop
                // all following threads.

    }

    void threads_join(objects * objs) {

        unsigned int iSink;

        // +----------------------------------------------------------+
        // | Raw                                                      |
        // +----------------------------------------------------------+  

            // +------------------------------------------------------+
            // | Source                                               |
            // +------------------------------------------------------+  

                thread_join(objs->asrc_hops_raw_object->thread);

            // +------------------------------------------------------+
            // | Sinks                                                |
            // +------------------------------------------------------+   
                
                for (iSink = 0; iSink < objs->asnk_hops_raw_object_count; iSink++) {
                    thread_join(objs->asnk_hops_raw_objects[iSink]->thread);
                }

            // +------------------------------------------------------+
            // | Connector                                            |
            // +------------------------------------------------------+  

                thread_join(objs->acon_hops_raw_object->thread);

        // +----------------------------------------------------------+
        // | Mapping                                                  |
        // +----------------------------------------------------------+  

            // +------------------------------------------------------+
            // | Module                                               |
            // +------------------------------------------------------+  

                thread_join(objs->amod_mapping_object->thread);

            // +------------------------------------------------------+
            // | Sinks                                                |
            // +------------------------------------------------------+   
                
                for (iSink = 0; iSink < objs->asnk_hops_mapping_object_count; iSink++) {
                    thread_join(objs->asnk_hops_mapping_objects[iSink]->thread);
                }

            // +------------------------------------------------------+
            // | Connector                                            |
            // +------------------------------------------------------+  

                thread_join(objs->acon_hops_mapping_object->thread);

        // +----------------------------------------------------------+
        // | Resample                                                 |
        // +----------------------------------------------------------+  

            // +------------------------------------------------------+
            // | Module                                               |
            // +------------------------------------------------------+  

                thread_join(objs->amod_resample_object->thread);               

            // +------------------------------------------------------+
            // | Sinks                                                |
            // +------------------------------------------------------+   
                
                for (iSink = 0; iSink < objs->asnk_hops_resample_object_count; iSink++) {
                    thread_join(objs->asnk_hops_resample_objects[iSink]->thread);
                }

            // +------------------------------------------------------+
            // | Connector                                            |
            // +------------------------------------------------------+  

                thread_join(objs->acon_hops_resample_object->thread);

        // +----------------------------------------------------------+
        // | STFT                                                     |
        // +----------------------------------------------------------+  

            // +------------------------------------------------------+
            // | Module                                               |
            // +------------------------------------------------------+  

                thread_join(objs->amod_stft_object->thread);               

            // +------------------------------------------------------+
            // | Sinks                                                |
            // +------------------------------------------------------+   
                
                for (iSink = 0; iSink < objs->asnk_spectra_stft_object_count; iSink++) {
                    thread_join(objs->asnk_spectra_stft_objects[iSink]->thread);
                }

            // +------------------------------------------------------+
            // | Connector                                            |
            // +------------------------------------------------------+  

                thread_join(objs->acon_spectra_stft_object->thread);

        // +----------------------------------------------------------+
        // | SSL                                                      |
        // +----------------------------------------------------------+  

            // +------------------------------------------------------+
            // | Module                                               |
            // +------------------------------------------------------+  

                thread_join(objs->amod_ssl_object->thread);               

            // +------------------------------------------------------+
            // | Sinks                                                |
            // +------------------------------------------------------+   
                
                for (iSink = 0; iSink < objs->asnk_pots_ssl_object_count; iSink++) {
                    thread_join(objs->asnk_pots_ssl_objects[iSink]->thread);
                }

            // +------------------------------------------------------+
            // | Connector                                            |
            // +------------------------------------------------------+  

                thread_join(objs->acon_pots_ssl_object->thread);

        // +----------------------------------------------------------+
        // | SST                                                      |
        // +----------------------------------------------------------+  

            // +------------------------------------------------------+
            // | Module                                               |
            // +------------------------------------------------------+  

                thread_join(objs->amod_sst_object->thread);               

            // +------------------------------------------------------+
            // | Sinks                                                |
            // +------------------------------------------------------+   
                
                for (iSink = 0; iSink < objs->asnk_tracks_sst_object_count; iSink++) {
                    thread_join(objs->asnk_tracks_sst_objects[iSink]->thread);
                }

            // +------------------------------------------------------+
            // | Connector                                            |
            // +------------------------------------------------------+  

                thread_join(objs->acon_tracks_sst_object->thread);

        // +----------------------------------------------------------+
        // | SSS                                                      |
        // +----------------------------------------------------------+  

            // +------------------------------------------------------+
            // | Module                                               |
            // +------------------------------------------------------+  

                thread_join(objs->amod_sss_object->thread);               

            // +------------------------------------------------------+
            // | Sinks                                                |
            // +------------------------------------------------------+   
                
                for (iSink = 0; iSink < objs->asnk_spectra_sss_object_count; iSink++) {
                    thread_join(objs->asnk_spectra_sss_objects[iSink]->thread);
                }

            // +------------------------------------------------------+
            // | Connector                                            |
            // +------------------------------------------------------+  

                thread_join(objs->acon_spectra_sss_object->thread);

        // +----------------------------------------------------------+
        // | SSPF                                                     |
        // +----------------------------------------------------------+  

            // +------------------------------------------------------+
            // | Module                                               |
            // +------------------------------------------------------+  

                thread_join(objs->amod_sspf_object->thread);               

            // +------------------------------------------------------+
            // | Sinks                                                |
            // +------------------------------------------------------+   
                
                for (iSink = 0; iSink < objs->asnk_spectra_sspf_object_count; iSink++) {
                    thread_join(objs->asnk_spectra_sspf_objects[iSink]->thread);
                }

            // +------------------------------------------------------+
            // | Connector                                            |
            // +------------------------------------------------------+  

                thread_join(objs->acon_spectra_sspf_object->thread);

    }