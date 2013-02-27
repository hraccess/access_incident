<?php
/**
 * @file
 * access_incident.openlayers_layers.inc
 */

/**
 * Implements hook_openlayers_layers().
 */
function access_incident_openlayers_layers() {
  $export = array();

  $openlayers_layers = new stdClass();
  $openlayers_layers->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
  $openlayers_layers->api_version = 1;
  $openlayers_layers->name = 'all_access_incident_location_layer';
  $openlayers_layers->title = 'All Access Incident Location Layer';
  $openlayers_layers->description = '';
  $openlayers_layers->data = array(
    'url' => 'sites/all/modules/custom/layers/all_access_incident_location_layer.kml',
    'formatOptions' => array(
      'extractStyles' => 1,
      'extractAttributes' => 1,
    ),
    'layer_type' => 'openlayers_layer_type_kml',
  );
  $export['all_access_incident_location_layer'] = $openlayers_layers;

  return $export;
}
