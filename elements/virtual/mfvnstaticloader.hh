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
 *  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 *  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 *  THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef MF_VN_STATIC_LOADER_HH
#define MF_VN_STATIC_LOADER_HH

#include <click/element.hh>

#include "mflogger.hh"
#include "mfvnmanager.hh"
#include "mfvnlsahandler.hh"
#include "mfvnneighbortablecompute.hh"
#include "mfvnroutingtablecompute.hh"

/*
 * Class comprising all components needed to define a virtual network
 * Virtual Topology manager has a hash table with key : VN guid and value : object of this class 
 */

//TODO make it concurrent

CLICK_DECLS

class MF_VNStaticLoader : public Element {

public:
	MF_VNStaticLoader();
	~MF_VNStaticLoader();

	const char* class_name() const        { return "MF_VNStaticLoader"; }

	int initialize(ErrorHandler *);
	int configure(Vector<String>&, ErrorHandler *);
	void run_timer(Timer*);


private:
	uint32_t myVirtualGuid;
	uint32_t virtualNetworkGuid;
	String configFile;
	String vtopoFile;
	String serviceFile;

	MF_VNManager *_vnManager;
	MF_VNLSAHandler *_vnLSAHandler;
	MF_VNNeighborTableCompute *_vnNeighborTableCompute;
	MF_VNRoutingTableCompute *_vnRoutingTableCompute;
	Timer timer;

};

CLICK_ENDDECLS
#endif