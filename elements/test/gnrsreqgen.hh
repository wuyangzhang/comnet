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
#ifndef GNRS_REQGEN_H
#define GNRS_REQGEN_H

#include <click/element.hh>
#include <click/timer.hh>
#include "mf.hh"
#include "mflogger.hh"

CLICK_DECLS

class GNRS_ReqGen : public Element {
 public:
  GNRS_ReqGen();
  ~GNRS_ReqGen();

  const char *class_name() const		{ return "GNRS_ReqGen"; }
  const char *port_count() const		{ return "0/1"; }
  const char *processing() const		{ return "h/h"; }
    
  int configure(Vector<String>&, ErrorHandler *);
  void run_timer(Timer *);
  int initialize(ErrorHandler *);

 private:
  /* iteration count */
  uint32_t _iter;
  Timer _timer;
  /* delay in seconds from init before first timer fires */
  uint32_t _delay;
  /* gap in seconds between two timer fires */
  uint32_t _period;

  MF_Logger logger;
};


CLICK_ENDDECLS
#endif 
