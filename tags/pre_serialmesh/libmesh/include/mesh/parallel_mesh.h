// $Id: parallel_mesh.h,v 1.2 2007-09-07 22:03:57 roystgnr Exp $

// The libMesh Finite Element Library.
// Copyright (C) 2002-2005  Benjamin S. Kirk, John W. Peterson
  
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
  
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
  
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA



#ifndef __parallel_mesh_h__
#define __parallel_mesh_h__

// C++ Includes   -----------------------------------

// Local Includes -----------------------------------
#include "mesh.h"

/**
 * The \p ParallelMesh class is derived from the \p MeshBase class,
 * and is intended to provide identical functionality to the user
 * but be fully parallelized in memory.
 * By "is intended" I mean that it doesn't work that way yet.  Don't
 * use this class unless you're developing or debugging it.
 *
 * Most methods are currently commented out, and will thus not
 * redefine the Mesh:: versions of those functions.  Methods for
 * which the Mesh:: version is obviously wrong for ParallelMesh
 * have been tagged by "error();"
*/

// ------------------------------------------------------------
// Mesh class definition
class ParallelMesh : public Mesh
{
 public:

  /**
   * Constructor.  Requires the dimension and optionally
   * a processor id.  Note that \p proc_id should always
   * be provided for multiprocessor applications.
   */
  ParallelMesh (unsigned int d);

  /**
   * Copy-constructor.  This should be able to take a
   * serial or parallel mesh.
   */
  ParallelMesh (const Mesh& other_mesh);  

  /**
   * Destructor.
   */
  ~ParallelMesh();

  /**
   * Deletes any elements which are neither local to this processor
   * nor "ghosts" neighboring local elements
   */
  void delete_nonlocal_elements();

  /**
   * Called on all processors at once, rebuilds any elements which
   * are local to other processors.
   */
  void restore_nonlocal_elements();

  /**
   * Reads the file specified by \p name.  Attempts to figure out the
   * proper method by the file extension.  This is now the only
   * way to read a mesh.  The \p Mesh then initializes its data
   * structures and is ready for use.
   *
   * In order to read the UNV and TetGen file types, you must
   * also pass a separate pointer to the MeshData object you will
   * use with this mesh, since these read methods expect it.
   */
//  void read (const std::string& name,
//	     MeshData* mesh_data=NULL);
  /**
   * Write the file specified by \p name.  Attempts to figure out the
   * proper method by the file extension.
   *
   * In order to write the UNV and TetGen file types, you must
   * also pass a separate pointer to the MeshData object you have been
   * using with this mesh, since these write methods expect it.
   */
//  void write (const std::string& name,
//	      MeshData* mesh_data=NULL);
  
  /**
   * Write to the file specified by \p name.  Attempts to figure out the
   * proper method by the file extension. Also writes data.
   */
//  void write (const std::string& name,
//	      const std::vector<Number>& values,
//	      const std::vector<std::string>& variable_names);

  /**
   * Clear all internal data.
   */
//  void clear();

  /**
   * Converts a mesh with higher-order
   * elements into a mesh with linear elements.  For 
   * example, a mesh consisting of \p Tet10 will be converted
   * to a mesh with \p Tet4 etc.
   */
//  void all_first_order ();

  /**
   * Converts a (conforming, non-refined) mesh with linear 
   * elements into a mesh with second-order elements.  For 
   * example, a mesh consisting of \p Tet4 will be converted
   * to a mesh with \p Tet10 etc.  Note that for some elements
   * like \p Hex8 there exist @e two higher order equivalents,
   * \p Hex20 and \p Hex27.  When \p full_ordered is \p true
   * (default), then \p Hex27 is built.  Otherwise, \p Hex20
   * is built.  The same holds obviously for \p Quad4, \p Prism6
   * ...
   */
//  void all_second_order (const bool full_ordered=true);
  
  /**
   * Generates a new mesh containing all the elements which
   * are assigned to processor \p pid.  This mesh is written
   * to the pid_mesh reference which you must create and pass
   * to the function.
   */
//  void create_pid_mesh (Mesh& pid_mesh,
//			const unsigned int pid) const;
  
  /**
   * Constructs a mesh called "new_mesh" from the current mesh by
   * iterating over the elements between it and it_end and adding
   * them to the new mesh.
   */
//  void create_submesh (Mesh& new_mesh,
//		       const_element_iterator& it,
//		       const const_element_iterator& it_end) const;
  


  /**
   * Virtual Functions Inherited From MeshBase which must be
   * redefined.
   * TODO[JWP]: Remember to comment later!!!!
   */
//  virtual unsigned int n_nodes () const { error(); }
//  virtual void reserve_nodes (const unsigned int) { }
//  virtual unsigned int n_elem ()  const { error(); }
//  virtual void reserve_elem (const unsigned int) { }

  /**
   * For meshes that don't store points/elems, these functions may be an issue!
   */
//  virtual const Point& point (const unsigned int i) const ;
//  virtual const Node&  node  (const unsigned int i) const ;
//  virtual Node& node (const unsigned int i) ;
//  virtual const Node* node_ptr (const unsigned int i) const ;
//  virtual Node* & node_ptr (const unsigned int i) ;
//  virtual Elem* elem (const unsigned int i) const ;

  /**
   * functions for adding /deleting nodes elements.
   */
//  virtual Node* add_point (const Point& n) ;
//  virtual void delete_node (Node* n) ;
//  virtual Elem* add_elem (Elem* e) ;
//  virtual void delete_elem (Elem* e) ;

  /**
   * Other functions from MeshBase requiring re-definition.
   */
//  virtual void find_neighbors ();
//  virtual void renumber_nodes_and_elements ();

#ifdef ENABLE_AMR
  /**
   * Delete subactive (i.e. children of coarsened) elements.
   * This removes all elements descended from currently active
   * elements in the mesh.
   */
//  virtual bool contract ();
#endif // #ifdef ENABLE_AMR


public:
  /**
   * Elem iterator accessor functions.
   */
//  element_iterator elements_begin () { error(); }
//  element_iterator elements_end   () { error(); }

//  element_iterator active_elements_begin () { error(); }
//  element_iterator active_elements_end   () { error(); }

//  element_iterator subactive_elements_begin () { error(); }
//  element_iterator subactive_elements_end   () { error(); }

//  element_iterator not_active_elements_begin () { error(); }
//  element_iterator not_active_elements_end   () { error(); }

//  element_iterator not_subactive_elements_begin () { error(); }
//  element_iterator not_subactive_elements_end   () { error(); }

//  element_iterator local_elements_begin ();
//  element_iterator local_elements_end   ();

//  element_iterator active_local_elements_begin ();
//  element_iterator active_local_elements_end   ();

//  element_iterator level_elements_begin (const unsigned int) { error(); }
//  element_iterator level_elements_end   (const unsigned int) { error(); }

//  element_iterator not_level_elements_begin (const unsigned int) { error(); }
//  element_iterator not_level_elements_end   (const unsigned int) { error(); }

//  element_iterator pid_elements_begin (const unsigned int) { error(); }
//  element_iterator pid_elements_end   (const unsigned int) { error(); }

//  element_iterator type_elements_begin (const ElemType) { error(); }
//  element_iterator type_elements_end   (const ElemType) { error(); }

//  element_iterator active_type_elements_begin (const ElemType) { error(); }
//  element_iterator active_type_elements_end   (const ElemType) { error(); }

//  element_iterator active_pid_elements_begin (const unsigned int) { error(); }
//  element_iterator active_pid_elements_end   (const unsigned int) { error(); }

  
  
  /**
   * const Elem iterator accessor functions.
   */
//  const_element_iterator elements_begin() const { error(); }
//  const_element_iterator elements_end()   const { error(); }
  
//  const_element_iterator active_elements_begin() const { error(); }
//  const_element_iterator active_elements_end()   const { error(); }
  
//  const_element_iterator subactive_elements_begin() const { error(); }
//  const_element_iterator subactive_elements_end()   const { error(); }
  
//  const_element_iterator not_active_elements_begin() const { error(); }
//  const_element_iterator not_active_elements_end()   const { error(); }

//  const_element_iterator not_subactive_elements_begin() const { error(); }
//  const_element_iterator not_subactive_elements_end()   const { error(); }

//  const_element_iterator local_elements_begin () const;
//  const_element_iterator local_elements_end   () const;

//  const_element_iterator active_local_elements_begin () const;
//  const_element_iterator active_local_elements_end   () const;

//  const_element_iterator level_elements_begin (const unsigned int) const { error(); }
//  const_element_iterator level_elements_end   (const unsigned int) const { error(); }

//  const_element_iterator not_level_elements_begin (const unsigned int) const { error(); }
//  const_element_iterator not_level_elements_end   (const unsigned int) const { error(); }

//  const_element_iterator pid_elements_begin (const unsigned int) const { error(); }
//  const_element_iterator pid_elements_end   (const unsigned int) const { error(); }

//  const_element_iterator type_elements_begin (const ElemType) const { error(); }
//  const_element_iterator type_elements_end   (const ElemType) const { error(); }

//  const_element_iterator active_type_elements_begin (const ElemType) const { error(); }
//  const_element_iterator active_type_elements_end   (const ElemType) const { error(); }

//  const_element_iterator active_pid_elements_begin (const unsigned int) const { error(); }
//  const_element_iterator active_pid_elements_end   (const unsigned int) const { error(); }
  
  
  
  
  
  
  
  /**
   * non-const Node iterator accessor functions.
   */
//  node_iterator nodes_begin() { error(); }
//  node_iterator nodes_end() { error(); }
  
//  node_iterator active_nodes_begin() { error(); }
//  node_iterator active_nodes_end() { error(); }

//  node_iterator local_nodes_begin  ();
//  node_iterator local_nodes_end    ();
  
//  node_iterator pid_nodes_begin (const unsigned int) { error(); }
//  node_iterator pid_nodes_end   (const unsigned int) { error(); }

  /**
   * const Node iterator accessor functions.
   */
//  const_node_iterator nodes_begin() const { error(); }
//  const_node_iterator nodes_end()   const { error(); }

//  const_node_iterator active_nodes_begin() const { error(); }
//  const_node_iterator active_nodes_end()   const { error(); }

//  const_node_iterator local_nodes_begin  () const;
//  const_node_iterator local_nodes_end    () const;

//  const_node_iterator pid_nodes_begin (const unsigned int) const { error(); }
//  const_node_iterator pid_nodes_end   (const unsigned int) const { error(); }

  
};





#endif