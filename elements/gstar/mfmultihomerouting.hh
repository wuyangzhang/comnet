/*
 *  Copyright (c) 2010-2013, Rutgers, The State University of New Jersey
 *  All rights reserved.
 *  
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *      * Redistributions of source code must retain the above copyright
 *        notice, this list of conditions and the following disclaimer.
 *      * Redistributions in binary form must reproduce the above copyright
 *        notice, this list of conditions and the following disclaimer in the
 *        documentation and/or other materials provided with the distribution.
 *      * Neither the name of the organization(s) stated above nor the
 *        names of its contributors may be used to endorse or promote products
 *        derived from this software without specific prior written permission.
 *  
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 *  ARE DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
 *  DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 *  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR ROUTINGS;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 *  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF 
 *  THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 * MF_MultiHomeRouting.hh
 *
 *  Created on: Jul 16, 2011
 *      Author: Kai Su
 */

#ifndef MF_MULTIHOMINGROUTING_HH_
#define MF_MULTIHOMINGROUTING_HH_

#include <click/element.hh>
#include <click/hashtable.hh>

#include "mf.hh"
#include "mfchunk.hh"
#include "mfbitratecache.hh"
#include "mfchunkmanager.hh"
#include "mflogger.hh"
#include "mfroutingtable.hh"
CLICK_DECLS

#define DEFAULT_BITRATE_LOOKUP_PORT 6060

/* for policy routing: network address assignment history */
struct assign_hist{
	uint32_t last_NA;
	uint32_t num_assigned;
};

typedef HashTable<uint32_t, struct assign_hist*> AssignTable;

class MF_MultiHomeRouting : public Element {
public:
  MF_MultiHomeRouting();
  ~MF_MultiHomeRouting();
  const char *class_name() const		{ return "MF_MultiHomeRouting"; }
  const char *port_count() const		{ return "1/1-2"; }
  const char *processing() const		{ return "h/h"; }

  int configure(Vector<String>&, ErrorHandler *);
  void push(int port, Packet *p);

private:
  MF_RoutingTable *_forwardElem;
  MF_ChunkManager *_chunkManager;

  uint32_t _myGUID;
  MF_BitrateCache *_bitrateCache; 
  AssignTable *_assignTable;
  
  
  MF_Logger logger;
  
  void handleChunkPkt(Packet *p);

  uint32_t assign_weighted_NA(Vector<NA> *vec_na, struct assign_hist *hist, 
                              uint16_t (&wts)[MAX_NUM_NA]);
  uint32_t assign_shortest_path_NA(Vector<NA> *vec_na, 
                                   struct assign_hist *hist);
  
  bool sendBitrateReq (uint32_t dst_GUID, uint32_t dst_NA, 
                         uint32_t next_hop_GUID); 
};

CLICK_ENDDECLS

#endif /* MF_MULTIHOMINGROUTING_HH_ */
