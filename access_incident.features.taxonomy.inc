<?php
/**
 * @file
 * access_incident.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function access_incident_taxonomy_default_vocabularies() {
  return array(
    'dashboard' => array(
      'name' => 'Dashboard',
      'machine_name' => 'dashboard',
      'description' => 'Dashboard',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
