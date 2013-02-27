<?php
/**
 * @file
 * access_incident.openlayers_maps.inc
 */

/**
 * Implements hook_openlayers_maps().
 */
function access_incident_openlayers_maps() {
  $export = array();

  $openlayers_maps = new stdClass();
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'geofield_formatter_map_zoomed';
  $openlayers_maps->title = 'Geofield Formatter Map Zoomed';
  $openlayers_maps->description = 'A Map Used for Geofield Output';
  $openlayers_maps->data = array(
    'width' => '600px',
    'height' => '400px',
    'image_path' => 'sites/all/modules/openlayers/themes/default_dark/img/',
    'css_path' => 'sites/all/modules/openlayers/themes/default_dark/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '69.038088991775, 31.052920902866',
        'zoom' => '5',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 0,
        'zoomBoxEnabled' => 1,
        'documentDrag' => 0,
      ),
      'openlayers_behavior_panzoombar' => array(
        'zoomWorldIcon' => 0,
        'panIcons' => 1,
      ),
    ),
    'default_layer' => 'mapquest_osm',
    'layers' => array(
      'mapquest_osm' => 'mapquest_osm',
      'geofield_formatter' => 'geofield_formatter',
    ),
    'layer_weight' => array(
      'geofield_formatter' => '0',
      'in_openlayers_1' => '0',
      'incident_map_openlayers_1' => '0',
      'openlayers_geojson_picture_this' => '0',
    ),
    'layer_styles' => array(
      'openlayers_geojson_picture_this' => '0',
      'incident_map_openlayers_1' => '0',
      'in_openlayers_1' => '0',
      'geofield_formatter' => 'default_marker_red',
    ),
    'layer_styles_select' => array(
      'openlayers_geojson_picture_this' => '0',
      'incident_map_openlayers_1' => '0',
      'in_openlayers_1' => '0',
      'geofield_formatter' => 'default_marker_red',
    ),
    'layer_activated' => array(
      'geofield_formatter' => 'geofield_formatter',
      'openlayers_geojson_picture_this' => 0,
      'incident_map_openlayers_1' => 0,
      'in_openlayers_1' => 0,
    ),
    'layer_switcher' => array(
      'geofield_formatter' => 0,
      'openlayers_geojson_picture_this' => 0,
      'incident_map_openlayers_1' => 0,
      'in_openlayers_1' => 0,
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default',
      'temporary' => 'default',
    ),
  );
  $export['geofield_formatter_map_zoomed'] = $openlayers_maps;

  $openlayers_maps = new stdClass();
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'geofield_widget_map_zoomed';
  $openlayers_maps->title = 'Geofield Widget Map Zoomed';
  $openlayers_maps->description = 'A Map Used for Geofield Input';
  $openlayers_maps->data = array(
    'width' => '600px',
    'height' => '400px',
    'image_path' => 'sites/all/modules/openlayers/themes/default_dark/img/',
    'css_path' => 'sites/all/modules/openlayers/themes/default_dark/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '69.125973508218, 30.675702269751',
        'zoom' => '5',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_geofield' => array(
        'feature_types' => array(
          'point' => 'point',
          'path' => 'path',
          'polygon' => 'polygon',
        ),
        'allow_edit' => 1,
      ),
      'openlayers_behavior_keyboarddefaults' => array(),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 0,
        'zoomBoxEnabled' => 1,
        'documentDrag' => 1,
      ),
      'openlayers_behavior_panzoombar' => array(
        'zoomWorldIcon' => 0,
        'panIcons' => 1,
      ),
    ),
    'default_layer' => 'mapquest_osm',
    'layers' => array(
      'mapquest_osm' => 'mapquest_osm',
    ),
    'layer_weight' => array(
      'in_openlayers_1' => '0',
      'incident_map_openlayers_1' => '0',
      'openlayers_geojson_picture_this' => '0',
      'geofield_formatter' => '0',
    ),
    'layer_styles' => array(
      'geofield_formatter' => '0',
      'openlayers_geojson_picture_this' => '0',
      'incident_map_openlayers_1' => '0',
      'in_openlayers_1' => '0',
    ),
    'layer_styles_select' => array(
      'geofield_formatter' => '0',
      'openlayers_geojson_picture_this' => '0',
      'incident_map_openlayers_1' => '0',
      'in_openlayers_1' => '0',
    ),
    'layer_activated' => array(
      'geofield_formatter' => 0,
      'openlayers_geojson_picture_this' => 0,
      'incident_map_openlayers_1' => 0,
      'in_openlayers_1' => 0,
    ),
    'layer_switcher' => array(
      'geofield_formatter' => 0,
      'openlayers_geojson_picture_this' => 0,
      'incident_map_openlayers_1' => 0,
      'in_openlayers_1' => 0,
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'default',
      'select' => 'default',
      'temporary' => 'default',
    ),
  );
  $export['geofield_widget_map_zoomed'] = $openlayers_maps;

  $openlayers_maps = new stdClass();
  $openlayers_maps->disabled = FALSE; /* Edit this to true to make a default openlayers_maps disabled initially */
  $openlayers_maps->api_version = 1;
  $openlayers_maps->name = 'map_for_incidents';
  $openlayers_maps->title = 'Map For Incidents';
  $openlayers_maps->description = 'Map to display multiple incident locations';
  $openlayers_maps->data = array(
    'width' => '800px',
    'height' => '400px',
    'image_path' => 'sites/all/modules/openlayers/themes/default_dark/img/',
    'css_path' => 'sites/all/modules/openlayers/themes/default_dark/style.css',
    'proxy_host' => '',
    'hide_empty_map' => 0,
    'center' => array(
      'initial' => array(
        'centerpoint' => '69.257812500003, 30.221096574158',
        'zoom' => '5',
      ),
      'restrict' => array(
        'restrictextent' => 0,
        'restrictedExtent' => '',
      ),
    ),
    'behaviors' => array(
      'openlayers_behavior_attribution' => array(
        'seperator' => '',
      ),
      'openlayers_behavior_layerswitcher' => array(
        'ascending' => 1,
        'roundedCorner' => 1,
        'roundedCornerColor' => '#222222',
      ),
      'openlayers_behavior_navigation' => array(
        'zoomWheelEnabled' => 0,
        'zoomBoxEnabled' => 1,
        'documentDrag' => 0,
      ),
      'openlayers_behavior_panzoombar' => array(
        'zoomWorldIcon' => 0,
        'panIcons' => 1,
      ),
      'openlayers_behavior_popup' => array(
        'layers' => array(
          'in_openlayers_1' => 'in_openlayers_1',
          'all_access_incident_location_layer' => 0,
        ),
      ),
    ),
    'default_layer' => 'mapquest_osm',
    'layers' => array(
      'mapquest_osm' => 'mapquest_osm',
      'mapquest_openaerial' => 'mapquest_openaerial',
      'in_openlayers_1' => 'in_openlayers_1',
      'all_access_incident_location_layer' => 'all_access_incident_location_layer',
    ),
    'layer_weight' => array(
      'in_openlayers_1' => '0',
      'all_access_incident_location_layer' => '0',
      'test_location_taxonomy_openlayers_1' => '0',
      'incident_map_openlayers_1' => '0',
      'openlayers_geojson_picture_this' => '0',
      'geofield_formatter' => '0',
    ),
    'layer_styles' => array(
      'geofield_formatter' => '0',
      'openlayers_geojson_picture_this' => '0',
      'incident_map_openlayers_1' => '0',
      'test_location_taxonomy_openlayers_1' => '0',
      'in_openlayers_1' => 'all_access_incident_map_style',
      'all_access_incident_location_layer' => 'all_access_incident_map_style',
    ),
    'layer_styles_select' => array(
      'geofield_formatter' => '0',
      'openlayers_geojson_picture_this' => '0',
      'incident_map_openlayers_1' => '0',
      'test_location_taxonomy_openlayers_1' => '0',
      'in_openlayers_1' => 'all_access_incident_map_style',
      'all_access_incident_location_layer' => 'all_access_incident_map_style',
    ),
    'layer_activated' => array(
      'in_openlayers_1' => 'in_openlayers_1',
      'all_access_incident_location_layer' => 'all_access_incident_location_layer',
      'geofield_formatter' => 0,
      'openlayers_geojson_picture_this' => 0,
      'incident_map_openlayers_1' => 0,
      'test_location_taxonomy_openlayers_1' => 0,
    ),
    'layer_switcher' => array(
      'in_openlayers_1' => 0,
      'all_access_incident_location_layer' => 0,
      'geofield_formatter' => 0,
      'openlayers_geojson_picture_this' => 0,
      'incident_map_openlayers_1' => 0,
      'test_location_taxonomy_openlayers_1' => 0,
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'all_access_incident_map_style',
      'select' => 'all_access_incident_map_style',
      'temporary' => 'all_access_incident_map_style',
    ),
  );
  $export['map_for_incidents'] = $openlayers_maps;

  return $export;
}
