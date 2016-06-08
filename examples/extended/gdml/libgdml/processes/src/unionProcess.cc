//
// ********************************************************************
// * DISCLAIMER                                                       *
// *                                                                  *
// * The following disclaimer summarizes all the specific disclaimers *
// * of contributors to this software. The specific disclaimers,which *
// * govern, are listed with their locations in:                      *
// *   http://cern.ch/geant4/license                                  *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.                                                             *
// *                                                                  *
// * This  code  implementation is the  intellectual property  of the *
// * GEANT4 collaboration.                                            *
// * By copying,  distributing  or modifying the Program (or any work *
// * based  on  the Program)  you indicate  your  acceptance of  this *
// * statement, and all its terms.                                    *
// ********************************************************************
//
//
// $Id: unionProcess.cc,v 1.3 2002/06/03 12:09:32 radoone Exp $
// GEANT4 tag $Name: geant4-04-01-patch-01 $
//
// 
// --------------------------------------------------------------
// Comments
//
// --------------------------------------------------------------
//
#include "BooleanSolidTypeProcess.hh"

#include "boolean_union.hh"

class unionProcess : public BooleanSolidTypeProcess
{
public:
  unionProcess( const ProcessingContext* context = 0 )
  : BooleanSolidTypeProcess( context ) {
  }

  virtual ~unionProcess() {
  }

  // Analogical to SAX startElement callback
  virtual void StartElement( const std::string& name, const ASCIIAttributeList& attrs ) {
    //std::cout << "PROCESS::START OF TAG  : " << name << std::endl;

    SAXObject** obj = Context()->GetTopObject();

    boolean_union* union_lement = new boolean_union;

    m_obj = union_lement;
    *obj  = union_lement;
    
    BooleanSolidTypeProcess::StartElement( name, attrs );
  }

  // Analogical to SAX endElement callback
  virtual void EndElement( const std::string& name ) {
    //std::cout << "PROCESS::END OF TAG  : " << name << std::endl;
    BooleanSolidTypeProcess::EndElement( name );
  }

  // Invoked whenever one of the daughter state processes has been popped-out of the state stack
  // The name passed-in as the argument is the name of the XML element for which that's been done
  virtual void StackPopNotify( const std::string& name ) {
    //std::cout << "PROCESS::union NOTIFIED AFTER THE TAG: " << name << std::endl;
    BooleanSolidTypeProcess::StackPopNotify( name );
  }

  // The name of the state this object will process
  virtual const std::string& State() const
  {
    static std::string tag = "union";
    return tag;
  }
};

DECLARE_PROCESS_FACTORY(unionProcess)